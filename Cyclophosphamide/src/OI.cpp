#include <Buttons/JoystickButton.h>
#include <Commands/Automatic/TurnToThenDrive.h>
#include <Commands/CanCollecterino/Arms/Induct.h>
#include <Commands/CanCollecterino/Arms/MoveArms.h>
#include <Commands/CanCollecterino/Arms/MoveWrist.h>
#include <Commands/CanCollecterino/Arms/Whack.h>
#include <Commands/CanCollecterino/CanToCraaawTransfer.h>
#include <Commands/CanCollecterino/Craaaw/CraaawActuate.h>
#include <Commands/CanCollecterino/MoveArmsFancy.h>
#include <Commands/Score.h>
#include <Commands/ToteLifting/DownUp.h>
#include <Commands/ToteLifting/LiftToHeightVelocity.h>
#include <Commands/ToteLifting/zeroing/ResetElevatorEncoder.h>
#include <Commands/ToteLifting/SafeDownUp.h>
#include <Commands/ToteLifting/SafeLiftToHeight.h>
#include <Commands/ToteIntake/ToteIntake.h>
#include <Commands/CanCollecterino/Collect.h>
#include <DoubleSolenoid.h>
#include <Joystick.h>
#include <OI.h>

#define SAFE_BUTTON(name, cmd) {if (name!=NULL){cmd;}}
#define VIRTUAL_OI true

OI::OI() {
	joystickLeft = new Joystick(0);
	joystickRight = new Joystick(1);
	op = new Joystick(2);

	// Can getting
	canArms = new JoystickButton(op, 1);
	canCollectFwd = new JoystickButton(op, 420);
	canCollectRvs = new JoystickButton(op, 421);
	canToCraaawTransfer = new JoystickButton(op, 9);
	craaawToggle = new JoystickButton(op, 16);

	// Tote stacking
	alignToteFwd = new JoystickButton(op, 14);
	alignToteRvs = new JoystickButton(op, 423);
	loadPos = new JoystickButton(op, 13);
	floorPos = new JoystickButton(op, 422);

	// Scoring
	floorLoader = new JoystickButton(op, 424);
	carryPos = new JoystickButton(op, 11);
	score = new JoystickButton(op, 5);

	// Overrides
	canArmOverrideUp = new JoystickButton(op, 425);
	canArmOverrideDown = new JoystickButton(op, 426);
	wristOverride = new JoystickButton(op, 2);
	toteLifterUp = new JoystickButton(joystickLeft, 4);
	toteLifterDown = new JoystickButton(joystickLeft, 5);
	zeroLifter = new JoystickButton(joystickRight, 5);

	// Driver buttons
	leftLoadButton = new JoystickButton(joystickRight, 5);
	rightLoadButton = new JoystickButton(joystickRight, 6);
	moveArmsWhackMode = new JoystickButton(joystickLeft, 1);
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
	createSwitch("canArms", canArms, new MoveArmsFancy(true),
			new MoveArmsFancy(false));
	createButton("transfer", canToCraaawTransfer, new CanToCraaawTransfer());
	createSwitch("collect Fwd", canCollectFwd,
			new Collect(Induct::forward, MoveWrist::close),
			new Collect(Induct::stopped, MoveWrist::open));
	createSwitch("collect Rvs", canCollectRvs,
			new Collect(Induct::reverse, MoveWrist::close),
			new Collect(Induct::stopped, MoveWrist::open));
	createSwitch("toggle craaaw", craaawToggle,
			new CraaawActuate(DoubleSolenoid::kReverse),
			new CraaawActuate(DoubleSolenoid::kForward));

	// Loading/stacking
	createSwitch("align tote Fwd", alignToteFwd,
			new ToteIntake(ToteIntake::forward),
			new ToteIntake(ToteIntake::stopped));
	createSwitch("align tote Rvs", alignToteRvs,
			new ToteIntake(ToteIntake::reverse),
			new ToteIntake(ToteIntake::stopped));
	createButton("lifter load", loadPos,
			new SafeLiftToHeight(TOTE_LIFTER_LOAD_HEIGHT));
	createButton("lifter floor", floorPos,
			new SafeLiftToHeight(TOTE_LIFTER_FLOOR_HEIGHT));

	// Scoring
	// TODO floor loader? What it do.
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
	createButton("arm up override", canArmOverrideUp, new MoveArms(CAN_POT_UP_POSITION));
	createButton("arm down override", canArmOverrideDown, new MoveArms(CAN_POT_DOWN_POSITION));

	// Special driver buttons
	SAFE_BUTTON(leftLoadButton,
			leftLoadButton->WhenPressed(new TurnToThenDrive(LOAD_LEFT_ANGLE)));
	SAFE_BUTTON(rightLoadButton,
			rightLoadButton->WhenPressed(new TurnToThenDrive(LOAD_RIGHT_ANGLE)));
	createButton("whack mode", moveArmsWhackMode, new Whack());
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

