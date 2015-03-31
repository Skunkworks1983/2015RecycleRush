#include <Commands/Automatic/TurnTo.h>
#include <cmath>

TurnTo::TurnTo(float targetAngle) {
	Requires(driveBase);
	SetTimeout(2.0);
	this->targetAngle = targetAngle;
	this->angleRemaining = 0;
}

void TurnTo::Initialize() {
	driveBase->startRotPID();
	driveBase->setTargetAngle(targetAngle);
}

void TurnTo::Execute() {
	angleRemaining = targetAngle - driveBase->getGyro()->GetYaw();
	driveBase->execute();
}

bool TurnTo::IsFinished() {
	return fabs(angleRemaining) <= AUTO_TURN_GYRO_THRESHOLD || IsTimedOut();
}

void TurnTo::End() {
	driveBase->setSpeed(0.0, 0.0, 0.0, 0.0);
	driveBase->zeroPIDOutput();
}

void TurnTo::Interrupted() {
	End();
}
