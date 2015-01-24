#ifndef Craaaw_H
#define Craaaw_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
#include "RobotMap.h"
#include "GyroDriver/IMU.h"

class Craaaw: public Subsystem
{
private:
	//LIFT_MOTOR_TYPE *liftereeno;
	DigitalInput *canDetected;
	Solenoid *craaawLocker;


public:
	Craaaw();
	~Craaaw();
	void toggle();
	bool getInput();


};

#endif
