#ifndef DriveBase_H
#define DriveBase_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "RobotMap.h"

class DriveBase: public Subsystem
{
private:
	DRIVE_MOTOR_TYPE *motorFrontLeft;
	DRIVE_MOTOR_TYPE *motorFrontRight;
	DRIVE_MOTOR_TYPE *motorBackLeft;
	DRIVE_MOTOR_TYPE *motorBackRight;
public:
	DriveBase();
	~DriveBase();
	void InitDefaultCommand();
	void setSpeed(double speedFrontLeft, double speedFrontRight,
			double speedBackLeft, double speedBackRight);
};

#endif
