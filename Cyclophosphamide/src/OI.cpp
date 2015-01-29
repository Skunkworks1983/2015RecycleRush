#include "OI.h"
#include "RobotMap.h"

OI::OI()
{
	joystickLeft = new Joystick(OI_JOYSTICK_LEFT);
	joystickRight = new Joystick(OI_JOYSTICK_RIGHT);
	stackButton = new SkunkButt(joystickLeft, OI_JOYSTICK_STACK);
	craaawUnactuate = new JoystickButton(joystickLeft, OI_CRAAAW_UNACTUATE);
}

OI::~OI() {
	delete joystickLeft;
	delete joystickRight;
	delete stackButton;
	delete craaawUnactuate;
}

Joystick *OI::getJoystickLeft() {
	return joystickLeft;
}

Joystick *OI::getJoystickRight() {
	return joystickRight;
}

bool OI::getUnactuate(){
	return craaawUnactuate->Get();
}

bool OI::checkStackFlag() {
	return stackButton->Get();
}
