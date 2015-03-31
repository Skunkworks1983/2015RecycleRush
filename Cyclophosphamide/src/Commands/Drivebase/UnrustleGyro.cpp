#include "UnrustleGyro.h"

UnrustleGyro::UnrustleGyro() {
	Requires(driveBase);
}

// Called just before this Command runs the first time
void UnrustleGyro::Initialize() {
	driveBase->zeroPIDOutput();
}

// Called repeatedly when this Command is scheduled to run
void UnrustleGyro::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool UnrustleGyro::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void UnrustleGyro::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void UnrustleGyro::Interrupted() {

}
