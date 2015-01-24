#include "OI.h"
#include "RobotMap.h"

OI::OI()
{
	joystickLeft = new Joystick(OI_JOYSTICK_LEFT);
	joystickRight = new Joystick(OI_JOYSTICK_RIGHT);

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
	if (stack_button_flag) {
		stack_button_flag = false;
		return true;
	}
	return false;
}
