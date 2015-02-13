#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	public:
		Joystick *joystickLeft;
		Joystick *joystickRight;
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

		JoystickButton *leftLoadButton;
		JoystickButton *rightLoadButton;

		JoystickButton *goToHighElevator;
		JoystickButton *goToMidElevator;
		JoystickButton *goToLowElevator;

		JoystickButton *dickAss;

		Button *toteLifterOverride;
	public:
		OI();
		~OI();
		Joystick *getJoystickLeft();
		Joystick *getJoystickRight();
		bool getUnactuate();
		void registerButtonListeners();
		bool isJoystickButtonPressed(bool isLeft, int val);
	};

#endif
