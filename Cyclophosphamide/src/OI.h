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
	JoystickButton *pushButton;
	JoystickButton *collectButton;
	JoystickButton *actuateButton;
	JoystickButton *unactuateButton;
	JoystickButton *liftarmsButton;
	JoystickButton *lowerarmsButton;
	JoystickButton *toteintakeButton;
	JoystickButton *totelifterButton;
	JoystickButton *motorfowardButton;
	JoystickButton *motorbackwardButton;
	JoystickButton *wristinButton;
	JoystickButton *wristoutButton;
	JoystickButton *armsupButton;
	JoystickButton *armsdownButton;



public:
	OI();
	~OI();
	Joystick *getJoystickLeft();
	Joystick *getJoystickRight();
	bool getUnactuate();
	bool checkStackFlag();
	void registerButtonListeners();
};

#endif
