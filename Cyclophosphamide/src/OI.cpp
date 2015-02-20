#include <Commands/Automatic/BestDrive.h>
#include <Commands/CanCollecterino/Arms/MoveArms.h>
#include <Commands/ToteHandling/LiftToHeight.h>
#include "OI.h"
#include "RobotMap.h"
#include "Commands/PushStack/PushStack.h"
#include "Commands/CanCollecterino/Craaaw/CraaawActuate.h"
#include "Commands/CanCollecterino/Craaaw/CraaawUnactuate.h"
#include "Commands/CanCollecterino/CanToCraaawTransfer.h"
#include "Commands/CanCollecterino/Arms/MoveArms.h"
#include "Commands/CanCollecterino/Arms/Induct.h"
#include "Commands/ToteHandling/ToteIntake.h"
#include "Commands/CanCollecterino/Collect.h"
#include "Commands/Automatic/TurnToThenDrive.h"
#include "Commands/ToteHandling/LiftToHeightVelocity.h"
#include "Commands/ToteHandling/LiftToHeight.h"
#include "Commands/ToteHandling/DownUp.h"
#include "Commands/CanCollecterino/Arms/MoveWrist.h"
#include "Commands/ToteHandling/ElevatorBangerang.h"

#define SAFE_BUTTON(name, cmd) {if (name!=NULL){cmd;}}

OI::OI() {
	joystickLeft = new Joystick(0);
	joystickRight = new Joystick(1);
	joystickOperator = new Joystick(2);

	canToClawTransfer = new JoystickButton(joystickOperator, 9);
	toteIntake = new JoystickButton(joystickOperator, 14);
	stackThenLoadPos = new JoystickButton(joystickOperator, 13);
	stackThenCarryPos = new JoystickButton(joystickOperator, 12);
	moveArmsWhackMode = new JoystickButton(joystickOperator, 8);
	toteLifterFloor = new JoystickButton(joystickOperator, 6);
	toteLifterCarry = new JoystickButton(joystickOperator, 5);
	toteLifterLift = new JoystickButton(joystickOperator, 10);
	toteLifterThirdPos = new JoystickButton(joystickOperator, 11);
	pushSwitch = new JoystickButton(joystickOperator, 7);
	wrist = new JoystickButton(joystickOperator, 2);
	collect = new JoystickButton(joystickOperator, 1);
	toteIntakeFwd = new JoystickButton(joystickOperator, 4);
	toteIntakeRvs = new JoystickButton(joystickOperator, 3);

	leftLoadButton = new JoystickButton(joystickRight, 5);
	rightLoadButton = new JoystickButton(joystickRight, 6);
}

OI::~OI() {
	delete joystickLeft;
	delete joystickRight;
	delete joystickOperator;
	delete pushSwitch;
	delete toteIntake;
	delete toteLifterFloor;
	delete toteLifterCarry;
	delete toteLifterLift;
	delete toteLifterThirdPos;
	delete moveArmsWhackMode;
	delete leftLoadButton;
	delete rightLoadButton;
	delete stackThenCarryPos;
	delete stackThenLoadPos;
	delete canToClawTransfer;
	delete collect;
	delete toteIntakeFwd;
	delete toteIntakeRvs;
	delete wrist;
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
	SAFE_BUTTON(moveArmsWhackMode,
			moveArmsWhackMode->WhenPressed(new MoveArms(CAN_POT_KNOCK)));
	SAFE_BUTTON(canToClawTransfer,
			canToClawTransfer->WhenPressed(new CanToCraaawTransfer()));
	SAFE_BUTTON(collect, collect->WhileHeld(new Induct()));

	// Loading/stacking
	SAFE_BUTTON(toteIntake,
			toteIntake->WhenPressed(new ToteIntake(ToteIntake::forward)));
	SAFE_BUTTON(toteIntake,
			toteIntake->WhenReleased(new ToteIntake(ToteIntake::stopped)));
	SAFE_BUTTON(toteIntakeFwd,
			toteIntakeFwd->WhenPressed(new ToteIntake(ToteIntake::forward)));
	SAFE_BUTTON(toteIntakeFwd,
			toteIntakeFwd->WhenReleased(new ToteIntake(ToteIntake::stopped)));
	SAFE_BUTTON(toteIntakeRvs,
			toteIntakeRvs->WhenPressed(new ToteIntake(ToteIntake::reverse)));
	SAFE_BUTTON(toteIntakeRvs,
			toteIntakeRvs->WhenReleased(new ToteIntake(ToteIntake::stopped)));
	SAFE_BUTTON(stackThenLoadPos,
			stackThenLoadPos->WhenPressed(new DownUp(DownUp::load)));
	SAFE_BUTTON(stackThenCarryPos,
			stackThenCarryPos->WhenPressed(new DownUp(DownUp::carry)));

	// Scoring
	SAFE_BUTTON(toteLifterFloor,
			toteLifterFloor->WhenReleased(new LiftToHeight(TOTE_LIFTER_FLOOR_HEIGHT)));
	SAFE_BUTTON(toteLifterCarry,
			toteLifterCarry->WhenReleased(new LiftToHeight(TOTE_LIFTER_CARRY_HEIGHT)));
	SAFE_BUTTON(toteLifterLift,
			toteLifterLift->WhenReleased(new LiftToHeight(TOTE_LIFTER_STACK_HEIGHT)));
	SAFE_BUTTON(toteLifterThirdPos,
			toteLifterThirdPos->WhenReleased(new LiftToHeight(TOTE_LIFTER_STACK_HEIGHT)));

	// Stack delivery slides
	SAFE_BUTTON(pushSwitch,
			pushSwitch->WhenPressed(new PushStack(StackPusher::push, 1.0f)));
	SAFE_BUTTON(pushSwitch,
			pushSwitch->WhenReleased(new PushStack(StackPusher::pull, 1.0f)));

	// Overrides
	SAFE_BUTTON(wrist, wrist->WhenPressed(new MoveWrist(true)));
	SAFE_BUTTON(wrist, wrist->WhenReleased(new MoveWrist(false)));

	// Special driver buttons
	SAFE_BUTTON(leftLoadButton,
			leftLoadButton->WhenReleased(new TurnToThenDrive(LOAD_LEFT_ANGLE)));
	SAFE_BUTTON(rightLoadButton,
			rightLoadButton->WhenReleased(new TurnToThenDrive(LOAD_RIGHT_ANGLE)));

	// Old stuff
//	SAFE_BUTTON(toteLifterDown,
//			toteLifterDown->WhileHeld(new LiftToHeightVelocity(-.5)));
//	SAFE_BUTTON(toteLifterUp,
//			toteLifterUp->WhileHeld(new LiftToHeightVelocity(.5)));
//	SAFE_BUTTON(moveArmsUp,
//			moveArmsUp->WhenReleased(new MoveArms(CAN_POT_UP_POSITION)));
//	SAFE_BUTTON(moveArmsDown,
//			moveArmsDown->WhenReleased(new MoveArms(CAN_POT_DOWN_POSITION)));
//	SAFE_BUTTON(moveArmsKnock,
//			moveArmsKnock->WhenReleased(new MoveArms(CAN_POT_KNOCK)));
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
