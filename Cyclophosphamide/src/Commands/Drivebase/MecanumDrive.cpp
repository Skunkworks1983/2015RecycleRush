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
	} else {
		double sign = clockwise > 0 ? 1.0 : -1.0;
		clockwise -= OI_JOYSTICK_ROT_DEADBAND * sign;
	}

	if (abs(clockwise) < 0.9) {
		clockwise /= 2.0;
	}

	/*
	 * Sometimes the setpoint isn't high enough to actually move the drivebase,
	 * so there's a leftover error that causes latency when turning in the
	 * opposite direction. This corrects for that.
	 */
	if ((clockwise > 0 && driveBae->getError() < 0)
			|| (clockwise < 0 && driveBae->getError() > 0)) {
		driveBae->zeroPIDOutput();
	}

	// Cube inputs for fine control
	clockwise = pow(clockwise, 3.0);
	forward = pow(forward, 3.0);
	right = pow(right, 3.0);

	if (driveBae->isGyroEnabled()) {
		clockwise *= JOYSTICK_DEGREES_PER_TICK;
		// Don't increase the angle if the PIDOutput is already maxed
		if (driveBae->getClockwise() < 0.9) {
			double targetAngle = driveBae->getSetpoint() + clockwise;
			if (targetAngle > 180.0) {
				targetAngle += 180.0;
				targetAngle = fmod(targetAngle, 360.0);
				targetAngle -= 180.0;
			} else if (targetAngle < -180.0) {
				targetAngle -= 180.0;
				targetAngle = fmod(targetAngle, 360.0);
				targetAngle += 180.0;
			}

			driveBae->setSetpoint(targetAngle);
		}

		//SmartDashboard::PutNumber("PID setpoint", driveBase->getSetpoint());
		//SmartDashboard::PutNumber("PID error", driveBase->getError());

#if FIELD_ORIENTED
		// Field-oriented corrections
		double theta = driveBae->getGyro()->GetYaw();
		//SmartDashboard::PutNumber("Gyro Angle", theta);
		theta *= M_PI / 180.0;
		double temp = forward * cos(theta) + right * sin(theta);
		right = -forward * sin(theta) + right * cos(theta);
		forward = temp;
#endif
	} else { // If the gyro is not enabled
		// Set the speed directly without using PID
		driveBae->setClockwise(clockwise);
	}

	/*
	 * Correct for driving faster than driving left/right due to the
	 * shape of the drivebase
	 */
	forward *= DRIVE_ASPECT_RATIO;

	driveBae->setForward(-forward);
	driveBae->setRight(right);
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
