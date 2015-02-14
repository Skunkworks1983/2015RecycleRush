#ifndef COLLECTERINO_ARMS_H
#define COLLECTERINO_ARMS_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
#include "RobotMap.h"
#include "GyroDriver/IMU.h"

class CanCollecterino: public Subsystem, public PIDOutput, public PIDSource
{
private:
	CAN_MOTOR_TYPE *liftMotorLeft;
	CAN_MOTOR_TYPE *liftMotorRight;
	CAN_MOTOR_TYPE *grabMotorLeft;
	CAN_MOTOR_TYPE *grabMotorRight;
	DoubleSolenoid *wrists;

	AnalogInput *liftPot;
	PIDController *armPID;

	DigitalInput *canSensor;

	float setpoint;
public:
	CanCollecterino();
	~CanCollecterino();
	void InitDefaultCommand();
	void StallDiag();

	void setGrab(float value);
	void setWrist(DoubleSolenoid::Value value);
	void setArms(float value);

	void disableArms();
	bool armsWithinBounds();
	bool getCanSensor();
	void brakeArms(bool brake);

	virtual void PIDWrite(float f);
	virtual double PIDGet();
};

#endif
