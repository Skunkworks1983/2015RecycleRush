#include "OI.h"
#include "RobotMap.h"
#include "Commands/PushStack/PushPull.h"
#include "Commands/PushStack/PushStack.h"
#include "Subsystems/StackPusher.h"

#define SAFE_BUTTON(name, cmd) {if (name!=NULL){cmd;}}

OI::OI()
{
	joystickLeft = new Joystick(OI_JOYSTICK_LEFT);
	joystickRight = new Joystick(OI_JOYSTICK_RIGHT);
	pushStackButton = new JoystickButton(joystickLeft, OI_PUSH_STACK_BUTTON);
}

OI::~OI() {
	delete joystickLeft;
	delete joystickRight;
	delete pushStackButton;
}

Joystick *OI::getJoystickLeft() {
	return joystickLeft;
}

Joystick *OI::getJoystickRight() {
	return joystickRight;
}

void OI::registerButtonListeners() {
	SAFE_BUTTON(pushStackButton, pushStackButton->WhenReleased(new PushPull()));
}
