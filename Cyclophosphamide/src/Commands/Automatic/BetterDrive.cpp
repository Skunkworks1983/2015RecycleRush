#include "BetterDrive.h"
#define DRIVE_TICKS_TO_DISTANCE 0.0
#define AUTO_DRIVE_THRESHHOLD 0.0
BetterDrive::BetterDrive(float distance, double angle) {
	Requires(driveBase);
	targetAngle = angle;
	targetDistance = distance;
	distanceRemain = targetDistance;
}

// Called just before this Command runs the first time
void BetterDrive::Initialize() {
	driveBase->enablePIDAll(true);
	driveBase->setPIDAll(DRIVE_DRIVE_P, DRIVE_DRIVE_I, DRIVE_DRIVE_D);
	driveBase->setAll(targetDistance);
	billy = driveBase->getZero();
}

// Called repeatedly when this Command is scheduled to run
void BetterDrive::Execute() {
	// ayy lma0
}

// Make this return true when this Command no longer needs to run execute()
bool BetterDrive::IsFinished() {
	return driveBase->withinThreshhold(AUTO_DRIVE_THRESHHOLD, targetDistance, billy);
}

// Called once after isFinished returns true
void BetterDrive::End() {
	driveBase->setAll(0);
	driveBase->enablePIDAll(false);

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BetterDrive::Interrupted() {
	End();
}
