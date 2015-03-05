#include <Subsystems/DriveBae.h>
#include <Vision/FollowVision.h>
#include <Vision/VisionRunner.h>

#define FOLLOW_VISION_TOLERANCE 420	//TODO: change this

FollowVision::FollowVision(bool neverEnd) {
	Requires(driveBae);
	this->neverEnd = neverEnd;
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
	double xpos = VisionRunner::getInstance().getXPosition();
	return neverEnd ?
			false :
			xpos < FOLLOW_VISION_TOLERANCE && xpos > -FOLLOW_VISION_TOLERANCE;
}

// Called once after isFinished returns true
void FollowVision::End() {
	driveBae->enableStrafePID(false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FollowVision::Interrupted() {
	End();
}
