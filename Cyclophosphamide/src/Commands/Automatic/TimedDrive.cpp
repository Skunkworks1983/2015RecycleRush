#include <CANSpeedController.h>
#include <Commands/Automatic/TimedDrive.h>
#include <RobotMap.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Subsystems/DriveBae.h>
#include <Timer.h>
#include <chrono>
#include <cmath>

TimedDrive::TimedDrive(float t, float speed, DriveBae::MotorSide side, bool test) {
	Requires(driveBae);
	SetTimeout(t);
	this->speed = speed;
	this->side = side;
	this->test = test;
}

void TimedDrive::Initialize() {
	driveBae->setModeAll(CANSpeedController::kPercentVbus);
	if(test){
		driveBae->getMotor(side)->Set(-speed);
	} else {
		driveBae->setAll(-speed);
	}
}

void TimedDrive::Execute() {

}

bool TimedDrive::IsFinished() {
	return IsTimedOut();
}

void TimedDrive::End() {
	driveBae->setAll(0.0);
}

void TimedDrive::Interrupted() {
	End();
}
