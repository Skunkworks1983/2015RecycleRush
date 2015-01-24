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
		if ( !is_calibrating ) {
			Wait( 0.2 );
			driveBase->getGyro()->ZeroYaw();
			firstIteration = false;
			driveBase->Enable();
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
	}

	// Everything works up to here...

	clockwise *= JOYSTICK_DEGREES_PER_TICK;

	/*
	double targetAngle = driveBase->GetSetpoint() + 180 + clockwise;
	targetAngle = fmod(targetAngle, 360.0);
	targetAngle -= 180;

	driveBase->SetSetpoint(targetAngle);
	*/

#if FIELD_ORIENTED
	double theta = driveBase->getGyro()->GetYaw();
	SmartDashboard::PutNumber("Gyro Angle", theta);
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

	/*
	driveBase->setForward(forward);
	driveBase->setRight(right);
	driveBase->execute();
	*/
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
