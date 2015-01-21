#include "MecanumDrive.h"
#include "ResetGyro.h"
#include <math.h>

MecanumDrive::MecanumDrive() :
		CommandBase("MecanumDrive") {
	Requires(driveBase);
	firstIteration = true;
}

void MecanumDrive::Initialize() {
	driveBase->setSpeed(0, 0, 0, 0);
}

void MecanumDrive::Execute() {
	if(firstIteration){
		bool is_calibrating = driveBase->getGyro()->IsCalibrating();
		SmartDashboard::PutBoolean("Is calibrating", is_calibrating);
		if ( !is_calibrating ) {
			Wait( 0.2 );
			driveBase->getGyro()->ZeroYaw();
			firstIteration = false;
		}
	}

	double forward;
	double right;
	double clockwise;

#if ONE_STICK
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
	if (fabs(clockwise) < OI_JOYSTICK_ROT_DEADBAND) {
		clockwise = 0;
		SmartDashboard::PutBoolean("PID enabled", true);
	} else {
		SmartDashboard::PutBoolean("PID enabled", false);
		driveBase->setTargetAngle(driveBase->getGyro()->GetYaw());
	}

	clockwise *= MECANUM_ROTATION_CONSTANT;

#if FIELD_ORIENTED
	// Field-oriented corrections
	double theta = driveBase->getGyro()->GetYaw();
	SmartDashboard::PutNumber("Gyro Angle", theta);
	bool is_calibrating = driveBase->getGyro()->IsCalibrating();
	SmartDashboard::PutBoolean("Is calibrating", is_calibrating);
	theta *= M_PI / 180.0;
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

	driveBase->UsePIDOutput(driveBase->getError());
	SmartDashboard::PutNumber("PID error", driveBase->getError());
}

bool MecanumDrive::IsFinished() {
	return false;
}

void MecanumDrive::End() {
	driveBase->setSpeed(0, 0, 0, 0);
}

void MecanumDrive::Interrupted() {
	driveBase->setSpeed(0, 0, 0, 0);
}
