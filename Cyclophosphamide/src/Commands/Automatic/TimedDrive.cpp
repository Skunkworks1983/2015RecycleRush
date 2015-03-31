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
	if(test){
		driveBase->getMotor(side)->Set(-speed);
	} else {
		driveBase->setAll(-speed);
	}
}

void TimedDrive::Execute() {

}

bool TimedDrive::IsFinished() {
	return IsTimedOut();
}

void TimedDrive::End() {
	driveBase->setAll(0.0);
}

void TimedDrive::Interrupted() {
	End();
}
