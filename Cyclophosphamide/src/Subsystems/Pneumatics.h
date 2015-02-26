#ifndef Pneumatics_H
#define Pneumatics_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
/*!
 * Pneumatics give air pressure to go on or off.
 */
class Pneumatics: public Subsystem
{
private:
	DigitalInput *pressureSwitch;
	Compressor *relay;
public:
	Pneumatics();
	void InitDefaultCommand();
	void setState(bool state);
	bool isBelowPressure();
	bool isCompressorOn();
};

#endif
