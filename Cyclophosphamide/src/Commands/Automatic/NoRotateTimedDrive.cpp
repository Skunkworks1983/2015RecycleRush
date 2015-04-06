/*
 * NoRotateTimedDrive.cpp
 *
 *  Created on: Apr 4, 2015
 *      Author: S-4020395
 */

#include <Commands/Automatic/NoRotateTimedDrive.h>

NoRotateTimedDrive::NoRotateTimedDrive(float time, float speed) :
		CommandBase("NoRotateTimedDrive") {
	SetTimeout(time);
	this->speed = speed;
}

NoRotateTimedDrive::~NoRotateTimedDrive() {
}

void NoRotateTimedDrive::Initialize() {
	driveBase->setSpeed(0.0, 0.0, 0.0, 0.0);
	driveBase->setModeAll(CANSpeedController::ControlMode::kPercentVbus);
	driveBase->zeroPIDOutput();
	driveBase->startRotPID();
}
void NoRotateTimedDrive::Execute() {
	driveBase->setForward(-speed);
	CommandBase::driveBase->execute();
}
bool NoRotateTimedDrive::IsFinished() {
	return IsTimedOut();
}
void NoRotateTimedDrive::End() {
	driveBase->setAll(0.0);
	driveBase->stopRotPID();
}
void NoRotateTimedDrive::Interrupted() {
	End();
}
