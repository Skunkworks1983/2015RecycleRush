#ifndef Craaaw_H
#define DriveBase_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
#include "RobotMap.h"
#include "GyroDriver/IMU.h"

class Craaaw
{
private:
	//LIFT_MOTOR_TYPE *liftereeno;
	DigitalInput *canDetected;
	Solenoid *craaawLocker;


public:
	Craaaw();
	~Craaaw();
	void Toggle();
	bool getInput();


};

#endif
