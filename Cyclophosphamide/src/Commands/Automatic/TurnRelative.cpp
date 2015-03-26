#include "TurnRelative.h"

TurnRelative::TurnRelative(float delta) {
	Requires(driveBae);
	SetTimeout(1.0);
	this->delta = delta;
	this->targetAngle = 0;
}

// Called just before this Command runs the first time
void TurnRelative::Initialize() {
	driveBae->startRotPID();
	targetAngle = driveBae->getGyro()->GetYaw() + delta;
	driveBae->setTargetAngle(targetAngle);
}

// Called repeatedly when this Command is scheduled to run
void TurnRelative::Execute() {
	driveBae->execute();
}

// Make this return true when this Command no longer needs to run execute()
bool TurnRelative::IsFinished() {
	return fabs(targetAngle - driveBae->getGyro()->GetYaw())
			<= AUTO_TURN_GYRO_THRESHOLD || IsTimedOut();
}

// Called once after isFinished returns true
void TurnRelative::End() {
	driveBae->setSpeed(0.0, 0.0, 0.0, 0.0);
	driveBae->zeroPIDOutput();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnRelative::Interrupted() {
	End();
}
