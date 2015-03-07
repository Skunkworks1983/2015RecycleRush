#include <CANSpeedController.h>
#include <Commands/Automatic/TimedDrive.h>
#include <RobotMap.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Subsystems/DriveBae.h>
#include <Timer.h>
#include <chrono>
#include <cmath>

TimedDrive::TimedDrive(float t, float theta) {
	Requires(driveBae);
	duration = (long) t * 1000;
	targetTime = 0;

	// Using forward as zero heading with clockwise as positive
	double heading = theta * M_PI / 180.0;
	double forward = AUTO_DRIVE_SPEED * sin(heading);
	double right = AUTO_DRIVE_SPEED * cos(heading);
	backSlashSpeed = forward + right;
	forwardSlashSpeed = forward - right;
}

void TimedDrive::Initialize() {
	driveBae->setModeAll(CANSpeedController::kPosition);
	driveBae->setSpeed(backSlashSpeed, forwardSlashSpeed, forwardSlashSpeed,
			backSlashSpeed);
	targetTime = getTime() + duration;
}

void TimedDrive::Execute() {
	SmartDashboard::PutNumber("TimedDrive ms left", targetTime - GetTime());
}

bool TimedDrive::IsFinished() {
	return getTime() + duration > targetTime;
}

void TimedDrive::End() {
	driveBae->setSpeed(0.0, 0.0, 0.0, 0.0);
}

void TimedDrive::Interrupted() {
	End();
}

unsigned long TimedDrive::getTime() {
	using namespace std::chrono;
	unsigned long ms = duration_cast<milliseconds>(
			high_resolution_clock::now().time_since_epoch()).count();
	return ms;
}
