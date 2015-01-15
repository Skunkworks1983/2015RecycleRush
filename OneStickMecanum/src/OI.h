#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick *joystickLeft;
	Joystick *joystickRight;
public:
	OI();
	~OI();
	Joystick *getJoystickLeft();
	Joystick *getJoystickRight();
};

#endif
