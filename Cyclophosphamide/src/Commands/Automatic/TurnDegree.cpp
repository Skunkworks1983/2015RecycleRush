#include "TurnDegree.h"
#include <cmath>

TurnDegree::TurnDegree(float targetAngle) {
	Requires(driveBase);
	this->targetAngle = targetAngle;
	this->angleRemaining = 0;
}

void TurnDegree::Initialize() {
	driveBase->getGyro()->ZeroYaw();
}

void TurnDegree::Execute() {
	angleRemaining = targetAngle - driveBase->getGyro()->GetYaw();
	float turnScaleFactor = fabs(angleRemaining) / AUTO_TURN_SLOW_DOWN;
	float turnSpeed = fmin(AUTO_TURN_SPEED_MAX,
			(AUTO_TURN_SPEED_RANGE * turnScaleFactor) + AUTO_TURN_SPEED_MIN)
			* copysign(1.0, angleRemaining);

	if (fabs(angleRemaining) <= AUTO_TURN_GYRO_THRESHOLD) {
		turnSpeed = 0;
	}

	driveBase->setSpeed(turnSpeed, -turnSpeed, turnSpeed, -turnSpeed);
}

bool TurnDegree::IsFinished() {
	return fabs(angleRemaining) <= AUTO_TURN_GYRO_THRESHOLD;
}

void TurnDegree::End() {
	driveBase->setSpeed(0.0, 0.0, 0.0, 0.0);
}

void TurnDegree::Interrupted() {
	driveBase->setSpeed(0.0, 0.0, 0.0, 0.0);
}
