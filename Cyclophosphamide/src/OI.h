#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	public:
		Joystick *joystickLeft;
		Joystick *joystickRight;
		JoystickButton *pushButton;
		JoystickButton *pullButton;
		JoystickButton *collectButton;
		JoystickButton *actuateButton;
		JoystickButton *unactuateButton;
		JoystickButton *liftarmsButton;
		JoystickButton *lowerarmsButton;
		JoystickButton *toteIntakeButtonForward;
		JoystickButton *toteIntakeButtonReverse;
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

		JoystickButton *toteLifterUp;
		JoystickButton *toteLifterDown;

		JoystickButton *runPIDElevator;
	public:
		OI();
		~OI();
		Joystick *getJoystickLeft();
		Joystick *getJoystickRight();
		double getAnalogValue(int input);
		bool getUnactuate();
		void registerButtonListeners();
		bool isJoystickButtonPressed(bool isLeft, int val);
	};

#endif
