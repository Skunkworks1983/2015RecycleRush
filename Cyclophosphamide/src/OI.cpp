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
#define SAFE_BUTTON(name, cmd) {if (name!=NULL){cmd;}}

OI::OI() {
	joystickLeft = new Joystick(0);
	joystickRight = new Joystick(1);
	pushButton = new JoystickButton(joystickLeft, 11);
	pullButton = new JoystickButton(joystickLeft, 12);
	toteIntakeButtonForward = new JoystickButton(joystickLeft, 8);
	toteIntakeButtonReverse = new JoystickButton(joystickLeft, 7);
	leftLoadButton = new JoystickButton(joystickRight, 11);
	rightLoadButton = new JoystickButton(joystickRight, 12);
	toteLifterUp = new JoystickButton(joystickLeft, 6);
	toteLifterDown = new JoystickButton(joystickLeft, 4);
	runPIDElevator = new JoystickButton(joystickLeft, 7);
	moveArmsUp = new JoystickButton(joystickLeft, 420); //TODO real numbers
	moveArmsDown = new JoystickButton(joystickLeft, 421);
	unactuateButton = new JoystickButton(joystickLeft, 422);
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
	delete runPIDElevator;
	delete moveArmsUp;
	delete moveArmsDown;
	delete unactuateButton;
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
			toteIntakeButtonForward->WhileHeld(
					new ToteIntake(ToteIntake::forward)));
	SAFE_BUTTON(toteIntakeButtonReverse,
			toteIntakeButtonReverse->WhileHeld(
					new ToteIntake(ToteIntake::reverse)));

	SAFE_BUTTON(leftLoadButton,
			leftLoadButton->WhenReleased(new TurnTo(LOAD_LEFT_ANGLE)));
	SAFE_BUTTON(rightLoadButton,
			rightLoadButton->WhenReleased(new TurnTo(LOAD_RIGHT_ANGLE)));

	SAFE_BUTTON(toteLifterDown,
			toteLifterDown->WhileHeld(new LiftToHeightVelocity(-.5)));
	SAFE_BUTTON(toteLifterUp,
			toteLifterUp->WhileHeld(new LiftToHeightVelocity(.5)));
	SAFE_BUTTON(runPIDElevator,
			runPIDElevator->WhenPressed(new LiftToHeight(1100)));

	SAFE_BUTTON(moveArmsUp, moveArmsUp->WhenPressed(new MoveArms(true)));
	SAFE_BUTTON(moveArmsDown, moveArmsDown->WhenPressed(new MoveArms(false)));
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

bool OI::getUnactuate() {
	return unactuateButton->Get();
}
