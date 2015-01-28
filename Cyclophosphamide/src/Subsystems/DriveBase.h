#ifndef DriveBase_H
#define DriveBase_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
#include "RobotMap.h"
#include "GyroDriver/IMU.h"

class DriveBae: public PIDSubsystem
{
private:
	DRIVE_MOTOR_TYPE *motorFrontLeft;
	DRIVE_MOTOR_TYPE *motorFrontRight;
	DRIVE_MOTOR_TYPE *motorBackLeft;
	DRIVE_MOTOR_TYPE *motorBackRight;

	IMU *gyro;
	SerialPort *serialPort;

	double forward;
	double right;
	double clockwise;
public:
	DriveBae();
	~DriveBae();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	void setSpeed(double speedFrontLeft, double speedFrontRight,
			double speedBackLeft, double speedBackRight);
	IMU *getGyro();
	void setTargetAngle(double theta);

	void stopPID();
	void startPID();
	double getError();

	void setForward(double f);
	void setRight(double r);
	void setClockwise(double c);
	void execute();
};

#endif
