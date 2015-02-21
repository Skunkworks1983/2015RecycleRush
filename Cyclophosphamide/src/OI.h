#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	public:
		Joystick *joystickLeft;
		Joystick *joystickRight;
		Joystick *joystickOperator;

		JoystickButton *pushSwitch;
		JoystickButton *toteIntake;
		JoystickButton *canCollectFwd;
		JoystickButton *canCollectRvs;
		JoystickButton *toggleCoop;
		JoystickButton *canToCraaawTransfer;
		JoystickButton *score;

		JoystickButton *leftLoadButton;
		JoystickButton *rightLoadButton;

		JoystickButton *toteLifterFloor;
		JoystickButton *toteLifterCarry;
		JoystickButton *toteLifterLift;
		JoystickButton *toteLifterThirdPos;
		JoystickButton *stackThenLoadPos;
		JoystickButton *stackThenCarryPos;

		JoystickButton *moveArmsWhackMode;
		JoystickButton *canCollector;
		JoystickButton *collect;
		JoystickButton *wrist;
		JoystickButton *armsToggle;

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
