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
	SAFE_BUTTON(canArms, canArms->WhenPressed(new MoveArmsFancy(true)));
	SAFE_BUTTON(canArms, canArms->WhenReleased(new MoveArmsFancy(false)));
	SAFE_BUTTON(canToCraaawTransfer,
			canToCraaawTransfer->WhenPressed(new CanToCraaawTransfer()));
	SAFE_BUTTON(canCollectFwd,
			canCollectFwd->WhenPressed(
					new Collect(Induct::forward, MoveWrist::close)));
	SAFE_BUTTON(canCollectFwd,
			canCollectFwd->WhenReleased(
					new Collect(Induct::stopped, MoveWrist::open)));
	SAFE_BUTTON(canCollectRvs,
			canCollectRvs->WhenPressed(
					new Collect(Induct::reverse, MoveWrist::close)));
	SAFE_BUTTON(canCollectRvs,
			canCollectRvs->WhenReleased(
					new Collect(Induct::reverse, MoveWrist::open)));
	SAFE_BUTTON(craaawToggle,
			craaawToggle->WhenPressed(
					new CraaawActuate(DoubleSolenoid::kReverse)));
	SAFE_BUTTON(craaawToggle,
			craaawToggle->WhenReleased(
					new CraaawActuate(DoubleSolenoid::kForward)));

	// Loading/stacking
	SAFE_BUTTON(alignToteFwd,
			alignToteFwd->WhenPressed(new ToteIntake(ToteIntake::forward)));
	SAFE_BUTTON(alignToteFwd,
			alignToteFwd->WhenReleased(new ToteIntake(ToteIntake::stopped)));
	SAFE_BUTTON(alignToteRvs,
			alignToteRvs->WhenPressed(new ToteIntake(ToteIntake::reverse)));
	SAFE_BUTTON(alignToteRvs,
			alignToteRvs->WhenReleased(new ToteIntake(ToteIntake::stopped)));
	SAFE_BUTTON(loadPos,
			loadPos->WhenPressed(new SafeLiftToHeight(TOTE_LIFTER_LOAD_HEIGHT)));
	SAFE_BUTTON(floorPos,
			floorPos->WhenPressed(new SafeLiftToHeight(TOTE_LIFTER_FLOOR_HEIGHT)));

	// Scoring
	// TODO floor loader? What it do.
	SAFE_BUTTON(score, score->WhenPressed(new Score()));
	SAFE_BUTTON(carryPos,
			carryPos->WhenPressed(new SafeLiftToHeight(TOTE_LIFTER_CARRY_HEIGHT)));

	// Overrides
	SAFE_BUTTON(wristOverride,
			wristOverride->WhenPressed(new MoveWrist(MoveWrist::close)));
	SAFE_BUTTON(wristOverride,
			wristOverride->WhenReleased(new MoveWrist(MoveWrist::open)));
	SAFE_BUTTON(toteLifterUp,
			toteLifterUp->WhileHeld(new LiftToHeightVelocity(.5)));
	SAFE_BUTTON(toteLifterUp,
			toteLifterUp->WhenReleased(new LiftToHeightVelocity(0)));
	SAFE_BUTTON(toteLifterDown,
			toteLifterDown->WhileHeld(new LiftToHeightVelocity(-.5)));
	SAFE_BUTTON(toteLifterDown,
			toteLifterDown->WhenReleased(new LiftToHeightVelocity(0)));
	SAFE_BUTTON(zeroLifter, zeroLifter->WhenPressed(new ResetElevatorEncoder()));
	SAFE_BUTTON(canArmOverrideUp,
			canArmOverrideUp->WhenPressed(new MoveArms(CAN_POT_UP_POSITION)));
	SAFE_BUTTON(canArmOverrideDown,
			canArmOverrideDown->WhenPressed(new MoveArms(CAN_POT_DOWN_POSITION)));

	// Special driver buttons
	SAFE_BUTTON(leftLoadButton,
			leftLoadButton->WhenReleased(new TurnToThenDrive(LOAD_LEFT_ANGLE)));
	SAFE_BUTTON(rightLoadButton,
			rightLoadButton->WhenReleased(new TurnToThenDrive(LOAD_RIGHT_ANGLE)));
	SAFE_BUTTON(moveArmsWhackMode, moveArmsWhackMode->WhenPressed(new Whack()));
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

