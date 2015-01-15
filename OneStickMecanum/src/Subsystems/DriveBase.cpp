#include "DriveBase.h"
#include "../RobotMap.h"
#include "../Commands/MecanumDrive.h"

DriveBase::DriveBase() :
		Subsystem("DriveBase") {
	motorFrontLeft = new DRIVE_MOTOR_TYPE(DRIVE_MOTOR_FRONT_LEFT);
	motorFrontRight = new DRIVE_MOTOR_TYPE(DRIVE_MOTOR_FRONT_RIGHT);
	motorBackLeft = new DRIVE_MOTOR_TYPE(DRIVE_MOTOR_BACK_LEFT);
	motorBackRight = new DRIVE_MOTOR_TYPE(DRIVE_MOTOR_BACK_RIGHT);
}

DriveBase::~DriveBase() {
	delete motorFrontLeft;
	delete motorFrontRight;
	delete motorBackLeft;
	delete motorBackRight;
}

void DriveBase::InitDefaultCommand() {
	SetDefaultCommand(new MecanumDrive);
}

void DriveBase::setSpeed(double speedFrontLeft, double speedFrontRight,
		double speedBackLeft, double speedBackRight) {
	motorFrontLeft->Set(speedFrontLeft);
	motorFrontRight->Set(-speedFrontRight);
	motorBackLeft->Set(speedBackLeft);
	motorBackRight->Set(-speedBackRight);
}

