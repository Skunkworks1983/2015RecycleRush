#include "FollowVision.h"

FollowVision::FollowVision() {
	Requires(driveBae);
}

// Called just before this Command runs the first time
void FollowVision::Initialize() {
	driveBae->setStrafeSetPoint(0);
	driveBae->enableStrafePID(true);
}

// Called repeatedly when this Command is scheduled to run
void FollowVision::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool FollowVision::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void FollowVision::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FollowVision::Interrupted() {

}
