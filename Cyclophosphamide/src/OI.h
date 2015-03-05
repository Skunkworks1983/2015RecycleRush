#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
public:
	Joystick *joystickLeft;
	Joystick *joystickRight;
	Joystick *op;

	// How many buttons does a man need?

	JoystickButton *alignToteFwd;
	JoystickButton *alignToteRvs;
	JoystickButton *canToCraaawTransfer;
	JoystickButton *score;
	JoystickButton *floorLoader;
	JoystickButton *leftLoadButton;
	JoystickButton *rightLoadButton;
	JoystickButton *carryPos;
	JoystickButton *loadPos;
	JoystickButton *floorPos;
	JoystickButton *moveArmsWhackMode;
	JoystickButton *canArms;
	JoystickButton *canCollectFwd;
	JoystickButton *canCollectRvs;
	JoystickButton *wristOverride;
	JoystickButton *craaawToggle;
	JoystickButton *toteLifterUp;
	JoystickButton *toteLifterDown;
	JoystickButton *zeroLifter;
	JoystickButton *canArmOverrideUp;
	JoystickButton *canArmOverrideDown;

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
