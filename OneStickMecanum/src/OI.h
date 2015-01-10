#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick *joystick;
	//Gyro *gyro;
public:
	OI();
	Joystick *getJoystick();
	//Gyro *getGyro();
};

#endif
