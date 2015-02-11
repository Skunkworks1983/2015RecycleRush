#include <Commands/Automatic/TurnTo.h>
#include <cmath>

TurnTo::TurnTo(float targetAngle) {
	Requires(driveBase);
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
	return fabs(angleRemaining) <= AUTO_TURN_GYRO_THRESHOLD;
}

void TurnTo::End() {
	driveBase->setSpeed(0.0, 0.0, 0.0, 0.0);
	driveBase->setTargetAngle(driveBase->getGyro()->GetYaw());
}

void TurnTo::Interrupted() {
	driveBase->setSpeed(0.0, 0.0, 0.0, 0.0);
	driveBase->setTargetAngle(driveBase->getGyro()->GetYaw());
}
