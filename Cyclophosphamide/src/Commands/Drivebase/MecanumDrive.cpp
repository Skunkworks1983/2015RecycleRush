#include <Commands/Drivebase/ZeroGyro.h>
#include "MecanumDrive.h"
#include <math.h>

MecanumDrive::MecanumDrive() :
		CommandBase("MecanumDrive") {
	Requires(driveBase);
}

void MecanumDrive::Initialize() {
	driveBase->setSpeed(0.0, 0.0, 0.0, 0.0);
	driveBase->setModeAll(CANSpeedController::ControlMode::kPercentVbus);
	driveBase->stopRotPID();
}

void MecanumDrive::Execute() {
	double forward;
	double right;
	double clockwise;

	forward = -oi->getJoystickLeft()->GetAxis(Joystick::kYAxis);
	right = oi->getJoystickLeft()->GetAxis(Joystick::kXAxis);
	clockwise = oi->getJoystickRight()->GetAxis(Joystick::kZAxis);

	if (fabs(forward) < JOYSTICK_DRIVE_DEADBAND) {
		forward = 0;
	}
	if (fabs(right) < JOYSTICK_DRIVE_DEADBAND) {
		right = 0;
	}
	if (fabs(clockwise) < JOYSTICK_ROT_DEADBAND) {
		clockwise = 0;
		driveBase->startRotPID();
	} else {
		double sign = clockwise > 0 ? 1.0 : -1.0;
		clockwise -= JOYSTICK_ROT_DEADBAND * sign;
		driveBase->stopRotPID();
		driveBase->zeroPIDOutput();
	}

	// Cube inputs for fine control
	clockwise = pow(clockwise, 3.0);
	/*
	 #if COMPETITION_BOT
	 clockwise *= .8;	//competition bot drives faster
	 #endif
	 */
	forward = pow(forward, 3.0);
	right = pow(right, 3.0);

	if (driveBase->isGyroEnabled()) {
#if FIELD_ORIENTED
		// Field-oriented corrections
		double theta = driveBase->getGyro()->GetYaw();
		theta *= M_PI / 180.0;
		double temp = forward * cos(theta) + right * sin(theta);
		right = -forward * sin(theta) + right * cos(theta);
		forward = temp;
#endif
	}

	/*
	 * Correct for driving faster than driving left/right due to the
	 * shape of the drivebase
	 */
	forward *= DRIVE_ASPECT_RATIO;

	driveBase->setForward(-forward);
	driveBase->setRight(right);
	if (clockwise != 0) {
		driveBase->setClockwise(-clockwise);
	}
	driveBase->execute();
}

bool MecanumDrive::IsFinished() {
	return false;
}

void MecanumDrive::End() {
	driveBase->setSpeed(0.0, 0.0, 0.0, 0.0);
}

void MecanumDrive::Interrupted() {
	driveBase->setSpeed(0.0, 0.0, 0.0, 0.0);
}
