#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	class SkunkButt : JoystickButton {
	private:
		bool flag;
	public:
		SkunkButt(GenericHID *joystick, int buttonNumber) : JoystickButton(joystick, buttonNumber) {
		}
		bool Get() {
			if (flag) {
				flag = false;
				return true;
			}
			return false;
		}

		void onPressed() {
			flag = true;
		}
	};

	Joystick *joystickLeft;
	Joystick *joystickRight;
	SkunkButt *stackButton;
	JoystickButton *craaawUnactuate;
public:
	OI();
	~OI();
	Joystick *getJoystickLeft();
	Joystick *getJoystickRight();
	bool getUnactuate();
	bool checkStackFlag();
};

#endif
