#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	public:
		Joystick *joystickLeft;
		Joystick *joystickRight;
		Joystick *joystickOperator;

		JoystickButton *pushToggle;
		JoystickButton *pullButton;
		JoystickButton *toteIntakeButtonForward;
		JoystickButton *moveArmsDown;

		JoystickButton *leftLoadButton;
		JoystickButton *rightLoadButton;

		JoystickButton *toteLifterUp;
		JoystickButton *toteLifterDown;
		JoystickButton *toteLifterFloor;
		JoystickButton *toteLifterCarry;
		JoystickButton *toteLifterLift;

		JoystickButton *moveArmsUp;
		JoystickButton *moveArmsKnock;
		JoystickButton *collect;
		JoystickButton *wristOpen;
		JoystickButton *wristClose;

	public:
		OI();
		~OI();
		Joystick *getJoystickLeft();
		Joystick *getJoystickRight();
		Joystick *getJoystickOperator();
		double getAnalogValue(int input);
		bool getUnactuate();
		void registerButtonListeners();
		bool isJoystickButtonPressed(bool isLeft, int val);
	};

#endif
