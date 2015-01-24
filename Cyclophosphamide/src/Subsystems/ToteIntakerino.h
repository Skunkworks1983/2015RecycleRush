#ifndef CrateIntakerino_H
#define CrateIntakerino_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "RobotMap.h"

class ToteIntakerino: public Subsystem
{
private:
	DigitalInput *isCanSensor;
	Talon *tote_rolly_motor;
public:
	ToteIntakerino();
	void InitDefaultCommand();
	bool hasTote();
	void setMotor(floaterino speed);
	void runIfTote();
};

#endif
