#ifndef COLLECTERINO_ARMS_H
#define COLLECTERINO_ARMS_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
#include "RobotMap.h"
#include "GyroDriver/IMU.h"

class CanCollecterino: public Subsystem
{
private:
	CAN_MOTOR_TYPE *liftMotorLeft;
	CAN_MOTOR_TYPE *liftMotorRight;
	CAN_MOTOR_TYPE *grabMotorLeft;
	CAN_MOTOR_TYPE *grabMotorRight;
	DoubleSolenoid *wrists;

	DigitalInput *canSensor;

	Relay *brakingRelay;
public:
	CanCollecterino();
	~CanCollecterino();
	void InitDefaultCommand();
	void StallDiag();
	void setGrab(float value);
	void setWrist(DoubleSolenoid::Value value);
	void setArms(float value);
	void disableArms();
	int armsWithinBounds(float setpoint, float bounds);
	bool getCanSensor();
	void brakeArms(bool brake);
};

#endif
