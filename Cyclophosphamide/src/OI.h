#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick *joystickLeft;
	Joystick *joystickRight;
	Button *stack_button;
	bool stack_button_flag;
public:
	OI();
	~OI();
	Joystick *getJoystickLeft();
	Joystick *getJoystickRight();
	bool checkStackFlag();
};

#endif
