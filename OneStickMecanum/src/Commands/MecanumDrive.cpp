#include "MecanumDrive.h"

#include <math.h>

MecanumDrive::MecanumDrive() :
		CommandBase("MecanumDrive") {
	Requires(driveBase);
}

void MecanumDrive::Initialize() {
	driveBase->setSpeed(0, 0, 0, 0);
}

void MecanumDrive::Execute() {
	double forward;
	double right;
	double clockwise;

#if HALO
		forward = -oi->getJoystickLeft()->GetAxis(Joystick::kYAxis);
		right = oi->getJoystickLeft()->GetAxis(Joystick::kXAxis);
		clockwise = oi->getJoystickLeft()->GetAxis(Joystick::kZAxis);
#else
		forward = -oi->getJoystickLeft()->GetAxis(Joystick::kYAxis);
		right = oi->getJoystickLeft()->GetAxis(Joystick::kXAxis);
		clockwise = oi->getJoystickRight()->GetAxis(Joystick::kZAxis);
#endif

	if (fabs(forward) < OI_JOYSTICK_DRIVE_DEADBAND) {
		forward = 0;
	}
	if (fabs(right) < OI_JOYSTICK_DRIVE_DEADBAND) {
		right = 0;
	}
	if (fabs(clockwise) < OI_JOYSTICK_DRIVE_DEADBAND) {
		clockwise = 0;
	}

	clockwise *= MECANUM_ROTATION_CONSTANT;

#if FIELD_ORIENTED
	// Field-oriented corrections
	// TODO check for radians / degrees issues
	double theta = driveBase->getGyro()->GetYaw();
	theta *= M_PI / 180.0;
	SmartDashboard::PutNumber("Gyro Angle", theta);
	double temp = forward*cos(theta) + right*sin(theta);
	right = -forward*sin(theta) + right*cos(theta);
	forward = temp;
#endif

	// 'Kinematic transformation'
	double frontLeft = forward + clockwise + right;
	double frontRight = forward - clockwise - right;
	double backLeft = forward + clockwise - right;
	double backRight = forward - clockwise + right;

	driveBase->setSpeed(frontLeft, frontRight, backLeft, backRight);
}

bool MecanumDrive::IsFinished() {
	return false;
}

void MecanumDrive::End() {
	driveBase->setSpeed(0, 0, 0, 0);
}

void MecanumDrive::Interrupted() {

}
