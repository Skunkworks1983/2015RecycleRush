#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "utilities/AnalogRangeIOButton.h"

class OI {
public:
	Joystick *joystickLeft;
	Joystick *joystickRight;
	Joystick *op;

	// How many buttons does a man need?

	JoystickButton *alignToteFwd;
	JoystickButton *alignToteRvs;
	JoystickButton *canToCraaawTransfer;
	JoystickButton *leftLoadButton;
	JoystickButton *rightLoadButton;
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
	JoystickButton *toteLifterUpDriver;
	JoystickButton *toteLifterDownDriver;
	JoystickButton *toteIndex;
	JoystickButton *toteIndexFwd;
	JoystickButton *toteIndexRv;
	JoystickButton *wristToggleDriver;

	AnalogRangeIOButton *score;
	AnalogRangeIOButton *floorLoader;
	AnalogRangeIOButton *carryPos;

	OI();
	~OI();
	Joystick *getJoystickLeft();
	Joystick *getJoystickRight();
	Joystick *getJoystickOperator();
	double getAnalogValue(int input);
	bool getUnactuate();
	void registerButtonListeners();
	bool isJoystickButtonPressed(bool isLeft, int val);
	void createButton(std::string key, Button *b, Command *c);
	void createSwitch(std::string key, Button *b, Command *on, Command *off);
};

#endif
