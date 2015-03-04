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
		JoystickButton *alignTote;
		JoystickButton *canCollectFwd;
		JoystickButton *canCollectRvs;
		JoystickButton *canToCraaawTransfer;
		JoystickButton *score;

		JoystickButton *leftLoadButton;
		JoystickButton *rightLoadButton;

		JoystickButton *toteLifterFloor;
		JoystickButton *toteLifterCarry;
		JoystickButton *toteLifterTwoTotes;
		JoystickButton *toteLifterOneTote;
		JoystickButton *getNext;
		JoystickButton *getLast;

		JoystickButton *moveArmsWhackMode;
		JoystickButton *canCollector;
		JoystickButton *collect;
		JoystickButton *wrist;
		JoystickButton *armsToggle;
		JoystickButton *craaawOverride;
		JoystickButton *shoulderOverride;

		JoystickButton *toteLifterUp;
		JoystickButton *toteLifterDown;
		JoystickButton *zeroLifter;

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
