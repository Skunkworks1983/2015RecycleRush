#ifndef Pneumatics_H
#define Pneumatics_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Pneumatics: public Subsystem
{
private:
	DigitalInput *pressureSwitch;
	Relay *relay;
public:
	Pneumatics();
	void InitDefaultCommand();
	void setState(bool state);
	bool isBelowPressure();
	bool isCompressorOn();
};

#endif
