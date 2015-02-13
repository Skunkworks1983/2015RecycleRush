#include <Commands/Automatic/TurnTo.h>
#include <cmath>

TurnTo::TurnTo(float targetAngle) {
	Requires(driveBae);
	this->targetAngle = targetAngle;
	this->angleRemaining = 0;
}

void TurnTo::Initialize() {
	driveBae->startRotPID();
	driveBae->setTargetAngle(targetAngle);
}

void TurnTo::Execute() {
	angleRemaining = targetAngle - driveBae->getGyro()->GetYaw();
	driveBae->execute();
}

bool TurnTo::IsFinished() {
	return fabs(angleRemaining) <= AUTO_TURN_GYRO_THRESHOLD;
}

void TurnTo::End() {
	driveBae->setSpeed(0.0, 0.0, 0.0, 0.0);
	driveBae->zeroPIDOutput();
}

void TurnTo::Interrupted() {
	driveBae->setSpeed(0.0, 0.0, 0.0, 0.0);
	driveBae->zeroPIDOutput();
}
