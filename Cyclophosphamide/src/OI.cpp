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
	joystickOperator = new Joystick(2);

	// Can getting
	canCollector = new JoystickButton(joystickOperator, 1);
	canToCraaawTransfer = new JoystickButton(joystickOperator, 9);
	collect = new JoystickButton(joystickOperator, 1);

	// Tote stacking
	alignTote = new JoystickButton(joystickOperator, 14);
	getNext = new JoystickButton(joystickOperator, 13);

	// Scoring
	toteLifterCarry = new JoystickButton(joystickOperator, 11);
	toteLifterTwoTotes = new JoystickButton(joystickOperator, 8);
	toteLifterOneTote = new JoystickButton(joystickOperator, 10);
	score = new JoystickButton(joystickOperator, 5);

	// Overrides
	wristOverride = new JoystickButton(joystickOperator, 2);
	canCollectRvs = new JoystickButton(joystickOperator, 3);
	craaawOverride = new JoystickButton(joystickOperator, 16);
	armOverride = new JoystickButton(joystickOperator, 15);
	toteLifterUp = new JoystickButton(joystickLeft, 4);
	toteLifterDown = new JoystickButton(joystickLeft, 5);
	zeroLifter = new JoystickButton(joystickRight, 5);
	toteIntakeFwd = new JoystickButton(joystickOperator, 420);
	toteIntakeRvs = new JoystickButton(joystickOperator, 421);

	// Driver buttons
	leftLoadButton = new JoystickButton(joystickRight, 5);
	rightLoadButton = new JoystickButton(joystickRight, 6);
	moveArmsWhackMode = new JoystickButton(joystickLeft, 1);
}

OI::~OI() {
	delete joystickLeft;
	delete joystickRight;
	delete joystickOperator;
	delete alignTote;
	delete toteLifterCarry;
	delete toteLifterTwoTotes;
	delete toteLifterOneTote;
	delete moveArmsWhackMode;
	delete leftLoadButton;
	delete rightLoadButton;
	delete getNext;
	delete canCollector;
	delete collect;
	delete canCollectRvs;
	delete wristOverride;
	delete canToCraaawTransfer;
	delete armsToggle;
	delete score;
	delete armOverride;
	delete toteLifterUp;
	delete toteLifterDown;
	delete zeroLifter;
	delete toteIntakeFwd;
	delete toteIntakeRvs;
}

Joystick *OI::getJoystickOperator() {
	return joystickOperator;
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
	SAFE_BUTTON(canCollector,
			canCollector->WhenPressed(new MoveArmsFancy(true)));
	SAFE_BUTTON(canCollector,
			canCollector->WhenReleased(new MoveArmsFancy(false)));
	SAFE_BUTTON(canToCraaawTransfer,
			canToCraaawTransfer->WhenPressed(new CanToCraaawTransfer()));

	// Loading/stacking
	SAFE_BUTTON(alignTote,
			alignTote->WhenPressed(new ToteIntake(ToteIntake::forward)));
	SAFE_BUTTON(alignTote,
			alignTote->WhenReleased(new ToteIntake(ToteIntake::stopped)));
	SAFE_BUTTON(getNext, getNext->WhenPressed(new SafeDownUp(DownUp::load)));

	// Scoring
	SAFE_BUTTON(toteLifterTwoTotes,
			toteLifterTwoTotes->WhenReleased(new SafeLiftToHeight(TOTE_LIFTER_TWO_TOTE, true)));
	SAFE_BUTTON(toteLifterOneTote,
			toteLifterOneTote->WhenReleased(new SafeLiftToHeight(TOTE_LIFTER_ONE_TOTE)));
	SAFE_BUTTON(score, score->WhenPressed(new Score()));

	// Overrides
	SAFE_BUTTON(wristOverride,
			wristOverride->WhenPressed(new MoveWrist(MoveWrist::close)));
	SAFE_BUTTON(wristOverride,
			wristOverride->WhenReleased(new MoveWrist(MoveWrist::open)));
	SAFE_BUTTON(canCollectRvs,
			canCollectRvs->WhenPressed(new Induct(Induct::reverse)));
	SAFE_BUTTON(canCollectRvs,
			canCollectRvs->WhenReleased(new Induct(Induct::stopped)));
	SAFE_BUTTON(craaawOverride,
			craaawOverride->WhenPressed(
					new CraaawActuate(DoubleSolenoid::kReverse)));
	SAFE_BUTTON(craaawOverride,
			craaawOverride->WhenReleased(
					new CraaawActuate(DoubleSolenoid::kForward)));
	SAFE_BUTTON(armOverride,
			armOverride->WhenPressed(new MoveArms(CAN_POT_UP_POSITION)));
	SAFE_BUTTON(armOverride,
			armOverride->WhenReleased(new MoveArms(CAN_POT_DOWN_POSITION)));
	SAFE_BUTTON(toteLifterUp,
			toteLifterUp->WhileHeld(new LiftToHeightVelocity(.5)));
	SAFE_BUTTON(toteLifterUp,
			toteLifterUp->WhenReleased(new LiftToHeightVelocity(0)));
	SAFE_BUTTON(toteLifterDown,
			toteLifterDown->WhileHeld(new LiftToHeightVelocity(-.5)));
	SAFE_BUTTON(toteLifterDown,
			toteLifterDown->WhenReleased(new LiftToHeightVelocity(0)));
	SAFE_BUTTON(zeroLifter, zeroLifter->WhenPressed(new ResetElevatorEncoder()));

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

