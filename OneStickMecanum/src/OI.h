#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick *joystickLeft;
	Joystick *joystickRight;
	JoystickButton *pushStackButton;
public:
	OI();
	~OI();
	Joystick *getJoystickLeft();
	Joystick *getJoystickRight();
	void registerButtonListeners();
};

#endif
