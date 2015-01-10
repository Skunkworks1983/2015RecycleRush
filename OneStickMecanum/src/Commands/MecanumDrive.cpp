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
	double forward = -oi->getJoystick()->GetAxis(Joystick::kYAxis);
	double right = oi->getJoystick()->GetAxis(Joystick::kXAxis);
	double clockwise = oi->getJoystick()->GetAxis(Joystick::kZAxis);
	// double theta = oi->getGyro()->GetAngle();

	if (fabs(forward) < OI_JOYSTICK_DRIVE_DEADBAND) {
		forward = 0;
	}
	if (fabs(right) < OI_JOYSTICK_DRIVE_DEADBAND) {
		right = 0;
	}
	if (fabs(clockwise) < OI_JOYSTICK_DRIVE_DEADBAND) {
		clockwise = 0;
	}

	clockwise *= MECANUM_TUNING_CONSTANT;

	// Field-oriented corrections
	// TODO check for degrees / radians issues
	/*double temp = forward*cos(theta) + right*sin(theta);
	right = -forward*sin(theta) + right*cos(theta);
	forward = temp;*/

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

	if(max>1){
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
