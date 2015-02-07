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
