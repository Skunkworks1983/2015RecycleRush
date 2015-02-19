#include <Commands/Drivebase/ZeroGyro.h>
#include "MecanumDrive.h"
#include <math.h>

MecanumDrive::MecanumDrive() :
		CommandBase("MecanumDrive") {
	Requires(driveBae);
}

void MecanumDrive::Initialize() {
	driveBae->setSpeed(0.0, 0.0, 0.0, 0.0);
	driveBae->setModeAll(CANSpeedController::ControlMode::kPercentVbus);
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
		driveBae->startRotPID();
	} else {
		double sign = clockwise > 0 ? 1.0 : -1.0;
		clockwise -= JOYSTICK_ROT_DEADBAND * sign;
		driveBae->stopRotPID();
		driveBae->zeroPIDOutput();
	}

	// Cube inputs for fine control
	clockwise = pow(clockwise, 3.0);
	forward = pow(forward, 3.0);
	right = pow(right, 3.0);

	if (driveBae->isGyroEnabled()) {
#if FIELD_ORIENTED
		// Field-oriented corrections
		double theta = driveBae->getGyro()->GetYaw();
		SmartDashboard::PutNumber("Gyro Angle", theta);
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

	driveBae->setForward(-forward);
	driveBae->setRight(-right);
	if(clockwise != 0) {
		driveBae->setClockwise(-clockwise);
	}
	driveBae->execute();
}

bool MecanumDrive::IsFinished() {
	return false;
}

void MecanumDrive::End() {
	driveBae->setSpeed(0.0, 0.0, 0.0, 0.0);
}

void MecanumDrive::Interrupted() {
	driveBae->setSpeed(0.0, 0.0, 0.0, 0.0);
}
