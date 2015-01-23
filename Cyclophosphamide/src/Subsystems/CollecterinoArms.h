#ifndef COLLECTERINO_ARMS_H
#define COLLECTERINO_ARMS_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
#include "RobotMap.h"
#include "GyroDriver/IMU.h"

class CanCollecterino
{
private:
	CAN_MOTOR_TYPE *liftMotorLeft;
	CAN_MOTOR_TYPE *liftMotorRight;
	CAN_MOTOR_TYPE *grabMotorLeft;
	CAN_MOTOR_TYPE *grabMotorRight;

	DigitalInput *canSensor;

	AnalogInput *liftPotLeft;
	AnalogInput *liftPotRight;

	Relay *brakingRelay;
public:
	CanCollecterino();
	~CanCollecterino();
	void induct();
	void expel();
	void rest();
	int getPotValue();
	bool getCanSensor();
	void moveUpPosition();
	void moveDownPosition();
	void brakeArms(bool brake);
};

#endif
