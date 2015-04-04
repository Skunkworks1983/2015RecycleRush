#include <CANSpeedController.h>
#include <Commands/Automatic/TimedDrive.h>
#include <RobotMap.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Subsystems/DriveBase.h>
#include <Timer.h>
#include <chrono>
#include <cmath>

TimedDrive::TimedDrive(float t, float speed, DriveBase::MotorSide side, bool test) {
	Requires(driveBase);
	SetTimeout(t);
	this->speed = speed;
	this->side = side;
	this->test = test;
}

void TimedDrive::Initialize() {
	driveBase->setModeAll(CANSpeedController::kPercentVbus);
	driveBase->startRotPID();
	if(test){
		driveBase->getMotor(side)->Set(-speed);
	} else {
		//driveBase->setAll(-speed);
		driveBase->setForward(speed);
	}
}

void TimedDrive::Execute() {
	driveBase->execute();
}

bool TimedDrive::IsFinished() {
	return IsTimedOut();
}

void TimedDrive::End() {
	driveBase->setAll(0.0);
	driveBase->stopRotPID();
}

void TimedDrive::Interrupted() {
	End();
}
