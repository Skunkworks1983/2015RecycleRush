#include "OI.h"
#include "RobotMap.h"

OI::OI()
{
	joystick = new Joystick(OI_JOYSTICK);
	//gyro = new Gyro(GYRO);
}

Joystick *OI::getJoystick() {
	return joystick;
}

/*Gyro *OI::getGyro() {
	return gyro;
}*/
