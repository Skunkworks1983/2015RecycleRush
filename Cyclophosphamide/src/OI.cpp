#include "OI.h"
#include "RobotMap.h"

OI::OI()
{
	joystickLeft = new Joystick(OI_JOYSTICK_LEFT);
	joystickRight = new Joystick(OI_JOYSTICK_RIGHT);
	stackButton = new SkunkButt(joystickLeft, OI_JOYSTICK_STACK);
}

OI::~OI() {
	delete joystickLeft;
	delete joystickRight;
}

Joystick *OI::getJoystickLeft() {
	return joystickLeft;
}

Joystick *OI::getJoystickRight() {
	return joystickRight;
}

bool OI::checkStackFlag() {
	return stackButton->Get();
}
