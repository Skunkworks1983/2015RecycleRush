#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
public:
	Joystick *joystickLeft;
	Joystick *joystickRight;
	Joystick *joystickOperator;

	JoystickButton *alignTote;
	JoystickButton *canCollectRvs;
	JoystickButton *canToCraaawTransfer;
	JoystickButton *score;

	JoystickButton *leftLoadButton;
	JoystickButton *rightLoadButton;

	JoystickButton *toteLifterCarry;
	JoystickButton *toteLifterTwoTotes;
	JoystickButton *toteLifterOneTote;
	JoystickButton *getNext;

	JoystickButton *moveArmsWhackMode;
	JoystickButton *canCollector;
	JoystickButton *collect;
	JoystickButton *wristOverride;
	JoystickButton *armsToggle;
	JoystickButton *craaawOverride;
	JoystickButton *armOverride;

	JoystickButton *toteLifterUp;
	JoystickButton *toteLifterDown;
	JoystickButton *zeroLifter;

	JoystickButton *toteIntakeFwd;
	JoystickButton *toteIntakeRvs;

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
