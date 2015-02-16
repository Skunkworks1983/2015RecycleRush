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
#include "Commands/Automatic/TurnTo.h"
#include "Commands/ToteHandling/LiftToHeightVelocity.h"
#include "Commands/ToteHandling/LiftToHeight.h"
#include "Commands/CanCollecterino/Arms/MoveWrist.h"
#define SAFE_BUTTON(name, cmd) {if (name!=NULL){cmd;}}

OI::OI() {
	joystickLeft = new Joystick(0);
	joystickRight = new Joystick(1);
	pushButton = new JoystickButton(joystickRight, 11);
	pullButton = new JoystickButton(joystickRight, 12);
	toteIntakeButtonForward = new JoystickButton(joystickRight, 8);
	toteIntakeButtonReverse = new JoystickButton(joystickRight, 7);
	leftLoadButton = new JoystickButton(joystickRight, 11);
	rightLoadButton = new JoystickButton(joystickRight, 12);

	toteLifterUp = new JoystickButton(joystickLeft, 6);
	toteLifterDown = new JoystickButton(joystickLeft, 4);
	toteLifterFloor = new JoystickButton(joystickLeft, 1);
	toteLifterCarry= new JoystickButton(joystickLeft, 3);
	toteLifterLift= new JoystickButton(joystickLeft, 2);

	moveArmsUp = new JoystickButton(joystickRight, 2); //TODO real numbers
	moveArmsDown = new JoystickButton(joystickRight, 3);
	collect = new JoystickButton(joystickRight, 4);
	wristOpen = new JoystickButton(joystickRight, 5);
	wristClose = new JoystickButton(joystickRight, 6);
}

OI::~OI() {
	delete joystickLeft;
	delete joystickRight;
	delete pushButton;
	delete pullButton;
	delete toteIntakeButtonForward;
	delete toteIntakeButtonReverse;
	delete leftLoadButton;
	delete rightLoadButton;
	delete toteLifterUp;
	delete toteLifterDown;
	delete moveArmsUp;
	delete moveArmsDown;
	delete collect;
	delete wristOpen;
	delete wristClose;
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
	SAFE_BUTTON(pushButton,
			pushButton->WhenReleased(new PushStack(StackPusher::push, 1.0f)));
	SAFE_BUTTON(pullButton,
			pullButton->WhenReleased(new PushStack(StackPusher::pull, 1.0f)));

	SAFE_BUTTON(toteIntakeButtonForward,
			toteIntakeButtonForward->WhenPressed(
					new ToteIntake(ToteIntake::forward)));
	SAFE_BUTTON(toteIntakeButtonReverse,
			toteIntakeButtonReverse->WhenPressed(
					new ToteIntake(ToteIntake::reverse)));

	SAFE_BUTTON(toteIntakeButtonForward,
			toteIntakeButtonForward->WhenReleased(
					new ToteIntake(ToteIntake::stopped)));
	SAFE_BUTTON(toteIntakeButtonReverse,
			toteIntakeButtonReverse->WhenReleased(
					new ToteIntake(ToteIntake::stopped)));

	/*
	SAFE_BUTTON(leftLoadButton,
			leftLoadButton->WhenReleased(new TurnTo(LOAD_LEFT_ANGLE)));
	SAFE_BUTTON(rightLoadButton,
			rightLoadButton->WhenReleased(new TurnTo(LOAD_RIGHT_ANGLE)));
	*/

	SAFE_BUTTON(toteLifterDown,
			toteLifterDown->WhileHeld(new LiftToHeightVelocity(-.5)));
	SAFE_BUTTON(toteLifterUp,
			toteLifterUp->WhileHeld(new LiftToHeightVelocity(.5)));
	SAFE_BUTTON(toteLifterFloor, toteLifterFloor->WhenPressed(new LiftToHeight(TOTE_LIFTER_FLOOR_HEIGHT)));
	SAFE_BUTTON(toteLifterCarry, toteLifterCarry->WhenPressed(new LiftToHeight(TOTE_LIFTER_CARRY_HEIGHT)));
	SAFE_BUTTON(toteLifterLift, toteLifterLift->WhenPressed(new LiftToHeight(TOTE_LIFTER_STACK_HEIGHT)));

	SAFE_BUTTON(moveArmsUp, moveArmsUp->WhenReleased(new MoveArms(true)));
	SAFE_BUTTON(moveArmsDown, moveArmsDown->WhenReleased(new MoveArms(false)));
	SAFE_BUTTON(collect, collect->WhileHeld(new Induct()));
	SAFE_BUTTON(wristOpen, wristOpen->WhenReleased(new MoveWrist(true)));
	SAFE_BUTTON(wristClose, wristClose->WhenReleased(new MoveWrist(false)));
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
