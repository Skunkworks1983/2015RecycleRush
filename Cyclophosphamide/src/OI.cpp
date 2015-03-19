#include <Buttons/JoystickButton.h>
#include <Commands/Armerino/Arms/Induct.h>
#include <Commands/Armerino/Arms/MoveArms.h>
#include <Commands/Armerino/Arms/MoveWrist.h>
#include <Commands/Armerino/Arms/Whack.h>
#include <Commands/Armerino/CanToCraaawTransfer.h>
#include <Commands/Armerino/CollectCan.h>
#include <Commands/Armerino/Craaaw/CraaawActuate.h>
#include <Commands/Armerino/IndexTote.h>
#include <Commands/Armerino/MoveArmsFancy.h>
#include <Commands/Automatic/TurnToThenDrive.h>
#include <Commands/Score.h>
#include <Commands/ToteIntake/OldToteIntake.h>
#include <Commands/ToteLifting/LiftToHeight.h>
#include <Commands/ToteLifting/LiftToHeightVelocity.h>
#include <Commands/ToteLifting/SafeLiftToHeight.h>
#include <Commands/ToteLifting/zeroing/ResetElevatorEncoder.h>
#include <Joystick.h>
#include <OI.h>
#include <RobotMap.h>
#include <SmartDashboard/SmartDashboard.h>
#include <string>

#define SAFE_BUTTON(name, cmd) {if (name!=NULL){cmd;}}
#define VIRTUAL_OI true
#define OPERATOR_PORT 2

OI::OI() {
	joystickLeft = new Joystick(0);
	joystickRight = new Joystick(1);
	op = new Joystick(OPERATOR_PORT);

	// Can getting
	canArms = new JoystickButton(op, 11);
	canCollectFwd = new JoystickButton(op, 13);
	canCollectRvs = new JoystickButton(op, 12);
	canToCraaawTransfer = new JoystickButton(op, 10);
	craaawToggle = new JoystickButton(op, 14);

	// Tote stacking
	alignToteFwd = new JoystickButton(op, 7);
	alignToteRvs = new JoystickButton(op, 8);
	loadPos = new JoystickButton(op, 6);
	floorPos = new JoystickButton(op, 5);

	// Scoring
	// TODO tune upper and lower thresholds
	floorLoader = new AnalogRangeIOButton(OPERATOR_PORT, Joystick::kXAxis, 0.5f,
			0.9f);
	carryPos = new AnalogRangeIOButton(OPERATOR_PORT, Joystick::kXAxis, -0.25f,
			0.25f);
	score = new AnalogRangeIOButton(OPERATOR_PORT, Joystick::kXAxis, -1.0f,
			-0.4f);

	// Overrides
	canArmOverrideUp = new JoystickButton(op, 3);
	canArmOverrideDown = new JoystickButton(op, 4);
	wristOverride = new JoystickButton(op, 2);
	toteLifterUp = new JoystickButton(op, 9);
	toteLifterDown = new JoystickButton(op, 15);
	zeroLifter = new JoystickButton(op, 16);

	// Driver buttons
	leftLoadButton = new JoystickButton(joystickRight, 5);
	rightLoadButton = new JoystickButton(joystickRight, 6);
	moveArmsWhackMode = new JoystickButton(joystickLeft, 1);
	toteLifterUpDriver = new JoystickButton(joystickLeft, 4);
	toteLifterDownDriver = new JoystickButton(joystickLeft, 5);
	toteIndex = new JoystickButton(joystickLeft, 2);
	toteIndexFwd = new JoystickButton(joystickLeft, 5);
	toteIndexRv = new JoystickButton(joystickLeft, 6);
	wristToggleDriver = new JoystickButton(joystickRight, 1);
}

OI::~OI() {
	delete alignToteFwd;
	delete alignToteRvs;
	delete canToCraaawTransfer;
	delete score;
	delete floorLoader;
	delete leftLoadButton;
	delete rightLoadButton;
	delete carryPos;
	delete loadPos;
	delete floorPos;
	delete moveArmsWhackMode;
	delete canArms;
	delete canCollectFwd;
	delete canCollectRvs;
	delete wristOverride;
	delete craaawToggle;
	delete toteLifterUp;
	delete toteLifterDown;
	delete zeroLifter;
	delete canArmOverrideUp;
	delete canArmOverrideDown;
	delete toteLifterUpDriver;
	delete toteLifterDownDriver;
	delete toteIndex;
	delete toteIndexFwd;
	delete toteIndexRv;
	delete wristToggleDriver;
}

Joystick *OI::getJoystickOperator() {
	return op;
}

Joystick *OI::getJoystickLeft() {
	return joystickLeft;
}

Joystick *OI::getJoystickRight() {
	return joystickRight;
}

double OI::getAnalogValue(int input) {
	//find input at port %input%
	//return analog value for that device
	return 0.0;
}

void OI::registerButtonListeners() {
	// Can manipulation
	createSwitch("canArms", canArms, new MoveArmsFancy(MoveArmsFancy::up),
			new MoveArmsFancy(MoveArmsFancy::down));
	createButton("transfer", canToCraaawTransfer, new CanToCraaawTransfer());
	createSwitch("collect Fwd", canCollectFwd,
			new Collect(Induct::forward, MoveWrist::close),
			new Collect(Induct::stopped, MoveWrist::close));
	createSwitch("collect Rvs", canCollectRvs,
			new Collect(Induct::reverse, MoveWrist::close),
			new Collect(Induct::stopped, MoveWrist::open));
	createSwitch("toggle craaaw", craaawToggle,
			new CraaawActuate(CraaawActuate::open),
			new CraaawActuate(CraaawActuate::close));

	// Loading/stacking
	SAFE_BUTTON(alignToteFwd,
			alignToteFwd->WhileHeld(new OldToteIntake(TOTE_INTAKE_MOTOR_FULL)));
	SAFE_BUTTON(alignToteRvs,
			alignToteRvs->WhileHeld(new OldToteIntake(-TOTE_INTAKE_MOTOR_FULL)));
	createButton("lifter load", loadPos,
			new SafeLiftToHeight(TOTE_LIFTER_LOAD_HEIGHT));
	createButton("lifter floor", floorPos,
			new SafeLiftToHeight(TOTE_LIFTER_FLOOR_HEIGHT));

	// Scoring
	createButton("floor loader", floorLoader,
			new SafeLiftToHeight(TOTE_LIFTER_ONE_TOTE));
	createButton("score", score, new Score());
	createButton("lifter carry", carryPos,
			new SafeLiftToHeight(TOTE_LIFTER_CARRY_HEIGHT));

	// Overrides
	createSwitch("wrist override", wristOverride,
			new MoveWrist(MoveWrist::close), new MoveWrist(MoveWrist::open));
	createSwitch("lifter up override", toteLifterUp,
			new LiftToHeightVelocity(.5), new LiftToHeightVelocity(0)); // TODO sketchy
	createSwitch("lifter down override", toteLifterDown,
			new LiftToHeightVelocity(-.5), new LiftToHeightVelocity(0));
	createButton("zero lifter", zeroLifter, new ResetElevatorEncoder());
	createButton("arm up override", canArmOverrideUp,
			new MoveArms(CAN_POT_UP_POSITION));
	createButton("arm down override", canArmOverrideDown,
			new MoveArms(CAN_POT_DOWN_POSITION));

	// Special driver buttons
	SAFE_BUTTON(leftLoadButton,
			leftLoadButton->WhenPressed(new TurnToThenDrive(LOAD_LEFT_ANGLE)));
	SAFE_BUTTON(rightLoadButton,
			rightLoadButton->WhenPressed(new TurnToThenDrive(LOAD_RIGHT_ANGLE)));
	createButton("whack mode", moveArmsWhackMode, new Whack());
	SAFE_BUTTON(toteLifterUpDriver,
			toteLifterUpDriver->WhenPressed(new LiftToHeightVelocity(.5)));
	SAFE_BUTTON(toteLifterUpDriver,
			toteLifterUpDriver->WhenReleased(new LiftToHeightVelocity(0)));
	SAFE_BUTTON(toteLifterDownDriver,
			toteLifterDownDriver->WhenPressed(new LiftToHeightVelocity(-.5)));
	SAFE_BUTTON(toteLifterDownDriver,
			toteLifterDownDriver->WhenReleased(new LiftToHeightVelocity(0)));
	createButton("index tote", toteIndex, new IndexTote());
	SAFE_BUTTON(toteIndexFwd, toteIndexFwd->WhenPressed(new Induct(Induct::forward, Induct::tote)));
	SAFE_BUTTON(toteIndexFwd, toteIndexFwd->WhenPressed(new Induct(Induct::stopped)));
	SAFE_BUTTON(toteIndexRv, toteIndexRv->WhenPressed(new Induct(Induct::reverse, Induct::tote)));
	SAFE_BUTTON(toteIndexRv, toteIndexRv->WhenReleased(new Induct(Induct::stopped)));
	createButton("hold tote", wristToggleDriver, new MoveWrist(MoveWrist::toggle));
}

void OI::createButton(std::string key, Button *b, Command *c) {
	SAFE_BUTTON(b, b->WhenPressed(c));
#if VIRTUAL_OI
	SmartDashboard::PutData(key, c);
#endif
}

void OI::createSwitch(std::string key, Button *b, Command *on, Command *off) {
	SAFE_BUTTON(b, b->WhenPressed(on));
	SAFE_BUTTON(b, b->WhenReleased(off));
#if VIRTUAL_OI
	SmartDashboard::PutData(key + " ON", on);
	SmartDashboard::PutData(key + " OFF", on);
#endif
}

bool OI::isJoystickButtonPressed(bool isLeft, int val) {
	if (isLeft) {
		return val > 0 && val < joystickLeft->GetButtonCount()
				&& joystickLeft->GetRawButton(val);
	} else {
		return val > 0 && val < joystickRight->GetButtonCount()
				&& joystickRight->GetRawButton(val);
	}
}

