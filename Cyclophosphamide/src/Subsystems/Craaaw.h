#ifndef Craaaw_H
#define Craaaw_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
#include "RobotMap.h"
#include "GyroDriver/IMU.h"

class Craaaw: public Subsystem
{
private:
	DigitalInput *canDetector;
	DoubleSolenoid *craaawLocker;
	bool stateOpen;

public:
	Craaaw();
	~Craaaw();
	void InitDefaultCommand();
	void toggle();
	bool getCanDetector();
};

#endif
