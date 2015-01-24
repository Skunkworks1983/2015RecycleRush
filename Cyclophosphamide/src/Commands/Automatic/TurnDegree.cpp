#include "TurnDegree.h"
#include <cmath>

TurnDegree::TurnDegree(float targetAngle) {
	Requires(driveBase);
	this->targetAngle = targetAngle;
	this->angleRemaining = 0;
}

void TurnDegree::Initialize() {
	driveBase->setTargetAngle(targetAngle);
}

void TurnDegree::Execute() {
	angleRemaining = targetAngle - driveBase->getGyro()->GetYaw();
	// The PID should automagically do the rest
}

bool TurnDegree::IsFinished() {
	return fabs(angleRemaining) <= AUTO_TURN_GYRO_THRESHOLD;
}

void TurnDegree::End() {
	driveBase->setSpeed(0.0, 0.0, 0.0, 0.0);
	driveBase->setTargetAngle(driveBase->getGyro()->GetYaw());
}

void TurnDegree::Interrupted() {
	driveBase->setSpeed(0.0, 0.0, 0.0, 0.0);
	driveBase->setTargetAngle(driveBase->getGyro()->GetYaw());
}
