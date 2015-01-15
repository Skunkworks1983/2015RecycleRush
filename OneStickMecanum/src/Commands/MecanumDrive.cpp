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

	if(HALO) {
		forward = -oi->getJoystickLeft()->GetAxis(Joystick::kYAxis);
		right = oi->getJoystickLeft()->GetAxis(Joystick::kXAxis);
		clockwise = oi->getJoystickLeft()->GetAxis(Joystick::kZAxis);
	} else {
		forward = -oi->getJoystickLeft()->GetAxis(Joystick::kYAxis);
		right = oi->getJoystickLeft()->GetAxis(Joystick::kXAxis);
		clockwise = oi->getJoystickRight()->GetAxis(Joystick::kZAxis);
	}

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

	// 'Kinematic transformation'
	double frontLeft = forward + clockwise + right;
	double frontRight = forward - clockwise - right;
	double backLeft = forward + clockwise - right;
	double backRight = forward - clockwise + right;

	// Normalize to the max
	double max = abs(frontLeft);
	if(abs(frontRight)>max) max = abs(frontRight);
	if(abs(backLeft)>max) max = abs(backLeft);
	if(abs(backRight)>max) max = abs(backRight);

	if(max>=1){
		frontLeft /= max;
		frontRight /= max;
		backLeft /= max;
		backRight /= max;
	}

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
