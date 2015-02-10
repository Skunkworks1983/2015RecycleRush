#include <Commands/Automatic/TimedDrive.h>
#include <chrono>
#include <cmath>

TimedDrive::TimedDrive(float t, float theta) {
	Requires(driveBase);
	duration = (long) t * 1000;
	timePassed = 0;
	targetTime = 0;

	// Using forward as zero heading with clockwise as positive
	double heading = theta * M_PI / 180.0;
	double forward = AUTO_DRIVE_SPEED * sin(heading);
	double right = AUTO_DRIVE_SPEED * cos(heading);
	backSlashSpeed = forward + right;
	forwardSlashSpeed = forward - right;
}

void TimedDrive::Initialize() {
	driveBase->setModeAll(CANSpeedController::kPosition);
	targetTime = getTime() + duration;
}

void TimedDrive::Execute() {
	timePassed = getTime();
	driveBase->setSpeed(backSlashSpeed, forwardSlashSpeed, forwardSlashSpeed,
			backSlashSpeed);
}

bool TimedDrive::IsFinished() {
	if (timePassed > targetTime) {
		return true;
	}
	return false;
}

void TimedDrive::End() {
	driveBase->setSpeed(0.0, 0.0, 0.0, 0.0);
}

void TimedDrive::Interrupted() {
	driveBase->setSpeed(0.0, 0.0, 0.0, 0.0);
}

unsigned long TimedDrive::getTime() {
	using namespace std::chrono;
	unsigned long ms = duration_cast<milliseconds>(
			high_resolution_clock::now().time_since_epoch()).count();
	return ms;
}
