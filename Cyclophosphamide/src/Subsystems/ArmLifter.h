#ifndef COLLECTERINO_ARMS_H
#define COLLECTERINO_ARMS_H

#include "WPILib.h"
#include "RobotMap.h"

/**
 * arm set value to lift, using PID.
 */

class ArmLifter: public Subsystem {
private:
	CAN_MOTOR_TYPE *liftMotorLeft;CAN_MOTOR_TYPE *liftMotorRight;

	AnalogInput *liftPot;
	PIDController *armPID;

	DigitalInput *canSensor;

	bool toggleArms;
public:
	ArmLifter();
	~ArmLifter();
	void InitDefaultCommand();

	void setArms(float value);

	void disableArms();
	bool armsWithinBounds();
	void brakeArms(bool brake);

	AnalogInput *getLiftPot();

	PIDController *getArmPID();

	bool getToggleArms();
	void doTheToggleArms();

	void getDatStatus();
	double getSetpoint();

	AnalogInput *getPot();
};

#endif
