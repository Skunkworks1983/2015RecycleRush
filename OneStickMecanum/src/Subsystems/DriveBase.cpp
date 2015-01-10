#include "DriveBase.h"
#include "../RobotMap.h"
#include "../Commands/MecanumDrive.h"

DriveBase::DriveBase() :
		Subsystem("DriveBase") {
	motorFrontLeft = new DRIVE_MOTOR_TYPE(DRIVE_MOTOR_FRONT_LEFT);
	LiveWindow::GetInstance()->AddActuator("Drive Base", "Motor Front Left",
			motorFrontLeft);
	motorFrontRight = new DRIVE_MOTOR_TYPE(DRIVE_MOTOR_FRONT_RIGHT);
	LiveWindow::GetInstance()->AddActuator("Drive Base", "Motor Front Right",
			motorFrontRight);
	motorBackLeft = new DRIVE_MOTOR_TYPE(DRIVE_MOTOR_BACK_LEFT);
	LiveWindow::GetInstance()->AddActuator("Drive Base", "Motor Back Left",
			motorBackLeft);
	motorBackRight = new DRIVE_MOTOR_TYPE(DRIVE_MOTOR_BACK_RIGHT);
	LiveWindow::GetInstance()->AddActuator("Drive Base", "Motor Back Right",
			motorBackRight);
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

