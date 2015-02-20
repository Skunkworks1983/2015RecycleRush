#include <Commands/Automatic/BestDrive.h>
#include <Commands/CanCollecterino/Arms/MoveArms.h>
#include <Commands/ToteHandling/LiftToHeight.h>
#include "OI.h"
#include "RobotMap.h"
#include "Commands/PushStack/PushStack.h"
#include "Commands/CanCollecterino/Craaaw/CraaawActuate.h"
#include "Commands/CanCollecterino/Craaaw/CraaawUnactuate.h"
#include "Commands/CanCollecterino/Arms/MoveArms.h"
#include "Commands/CanCollecterino/Arms/Induct.h"
#include "Commands/ToteHandling/ToteIntake.h"
#include "Commands/CanCollecterino/Collect.h"
#include "Commands/Automatic/TurnToThenDrive.h"
#include "Commands/ToteHandling/LiftToHeightVelocity.h"
#include "Commands/ToteHandling/LiftToHeight.h"
#include "Commands/CanCollecterino/Arms/MoveWrist.h"
#include "Commands/ToteHandling/ElevatorBangerang.h"

#define SAFE_BUTTON(name, cmd) {if (name!=NULL){cmd;}}

OI::OI() {
	joystickLeft = new Joystick(0);
	joystickRight = new Joystick(1);
	joystickOperator = new Joystick(2);

	pushToggle = new JoystickButton(joystickOperator, 8); // pushToggle
	pullButton = new JoystickButton(joystickOperator, 12); // fake
	toteIntakeButtonForward = new JoystickButton(joystickOperator, 6);
	leftLoadButton = new JoystickButton(joystickRight, 5);
	rightLoadButton = new JoystickButton(joystickRight, 6);

	toteLifterUp = new JoystickButton(joystickOperator, 10);
	toteLifterDown = new JoystickButton(joystickOperator, 12);
	toteLifterFloor = new JoystickButton(joystickOperator, 11);
	toteLifterCarry = new JoystickButton(joystickOperator, 9);
	toteLifterLift = new JoystickButton(joystickOperator, 7);

	moveArmsUp = new JoystickButton(joystickOperator, 5);
	moveArmsDown = new JoystickButton(joystickOperator, 4);
	moveArmsKnock = new JoystickButton(joystickOperator, 2);

	collect = new JoystickButton(joystickOperator, 3);
	wristOpen = new JoystickButton(joystickOperator, 1); // wristToggle
	wristClose = new JoystickButton(joystickOperator, 6); // fake
}

OI::~OI() {
	delete joystickLeft;
	delete joystickRight;
	delete joystickOperator;
	delete pushToggle;
	delete pullButton;
	delete toteIntakeButtonForward;
	delete moveArmsDown;
	delete leftLoadButton;
	delete rightLoadButton;
	delete toteLifterUp;
	delete toteLifterDown;
	delete moveArmsUp;
	delete moveArmsKnock;
	delete collect;
	delete wristOpen;
	delete wristClose;
}

Joystick *OI::getJoystickOperator(){
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
	SAFE_BUTTON(pushToggle,
			pushToggle->WhenReleased(new PushStack(StackPusher::toggle, 1.0f)));
//	SAFE_BUTTON(pullButton,
//			pullButton->WhenReleased(new PushStack(StackPusher::pull, 1.0f)));

	SAFE_BUTTON(toteIntakeButtonForward,
			toteIntakeButtonForward->WhenPressed(
					new ToteIntake(ToteIntake::forward)));

	SAFE_BUTTON(toteIntakeButtonForward,
			toteIntakeButtonForward->WhenReleased(
					new ToteIntake(ToteIntake::stopped)));

	SAFE_BUTTON(leftLoadButton,
			leftLoadButton->WhenReleased(new TurnToThenDrive(LOAD_LEFT_ANGLE)));
	SAFE_BUTTON(rightLoadButton,
			rightLoadButton->WhenReleased(new TurnToThenDrive(LOAD_RIGHT_ANGLE)));

	SAFE_BUTTON(toteLifterDown,
			toteLifterDown->WhileHeld(new LiftToHeightVelocity(-.5)));
	SAFE_BUTTON(toteLifterUp,
			toteLifterUp->WhileHeld(new LiftToHeightVelocity(.5)));

	SAFE_BUTTON(toteLifterFloor,
			toteLifterFloor->WhenReleased(new LiftToHeight(TOTE_LIFTER_FLOOR_HEIGHT)));
	SAFE_BUTTON(toteLifterCarry,
			toteLifterCarry->WhenReleased(new LiftToHeight(TOTE_LIFTER_CARRY_HEIGHT)));
	SAFE_BUTTON(toteLifterLift,
			toteLifterLift->WhenReleased(new LiftToHeight(TOTE_LIFTER_STACK_HEIGHT)));

	SAFE_BUTTON(moveArmsUp,
			moveArmsUp->WhenReleased(new MoveArms(CAN_POT_UP_POSITION)));
	SAFE_BUTTON(moveArmsDown,
			moveArmsDown->WhenReleased(new MoveArms(CAN_POT_DOWN_POSITION)));
	SAFE_BUTTON(moveArmsKnock,
			moveArmsKnock->WhenReleased(new MoveArms(CAN_POT_KNOCK)));
	SAFE_BUTTON(collect, collect->WhileHeld(new Induct()));
	SAFE_BUTTON(wristOpen, wristOpen->WhenReleased(new MoveWrist(true)));
	//SAFE_BUTTON(wristClose, wristClose->WhenReleased(new MoveWrist(false)));
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
