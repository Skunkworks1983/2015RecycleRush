#include "BetterDrive.h"
#define AUTO_DRIVE_THRESHHOLD 0.0

BetterDrive::BetterDrive(float distance, double angle) {
	Requires(driveBase);
	targetAngle = angle;
	targetDistance = distance;
	distanceRemain = targetDistance;
}

// Called just before this Command runs the first time
void BetterDrive::Initialize() {
	driveBase->zeroEncoders();
	driveBase->setModeAll(CANSpeedController::kPosition);
	driveBase->enablePIDAll(true);
	driveBase->setPIDAll(DRIVE_DRIVE_P, DRIVE_DRIVE_I, DRIVE_DRIVE_D);
	driveBase->setAll(targetDistance);
	billy = driveBase->getZero();
	SmartDashboard::PutNumber("Initial enc value", driveBase->getMotor(DriveBae::FRONT_LEFT)->GetEncPosition());
}

// Called repeatedly when this Command is scheduled to run
void BetterDrive::Execute() {
	// ayy lma0
	SmartDashboard::PutNumber("Current enc value", driveBase->getMotor(DriveBae::FRONT_LEFT)->GetEncPosition());
	SmartDashboard::PutNumber("Drive PID setpoint", driveBase->getMotor(DriveBae::FRONT_LEFT)->GetSetpoint());
}

// Make this return true when this Command no longer needs to run execute()
bool BetterDrive::IsFinished() {
	return driveBase->withinThreshhold(AUTO_DRIVE_THRESHHOLD, targetDistance, billy);
}

// Called once after isFinished returns true
void BetterDrive::End() {
	driveBase->setAll(0);
	driveBase->enablePIDAll(false);
	delete billy;
	SmartDashboard::PutNumber("Final enc value", driveBase->getMotor(DriveBae::FRONT_LEFT)->GetEncPosition());
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BetterDrive::Interrupted() {
	End();
}
