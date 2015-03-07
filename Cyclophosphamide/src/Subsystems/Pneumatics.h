#ifndef Pneumatics_H
#define Pneumatics_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
<<<<<<< HEAD
/*!
 * Pneumatics give air pressure to go on or off.
 */
class Pneumatics: public Subsystem
{
=======

class Pneumatics: public Subsystem {
>>>>>>> origin/master
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
