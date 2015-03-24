#include <CANSpeedController.h>
#include <Commands/Automatic/TimedDrive.h>
#include <RobotMap.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Subsystems/DriveBae.h>
#include <Timer.h>
#include <chrono>
#include <cmath>

TimedDrive::TimedDrive(float t, float theta, float speed) {
	Requires(driveBae);
	SetTimeout(t);

	// Using forward as zero heading with clockwise as positive
	double heading = theta * M_PI / 180.0;
	double forward = speed * sin(heading);
	double right = speed * cos(heading);
	backSlashSpeed = forward + right;
	forwardSlashSpeed = forward - right;
}

void TimedDrive::Initialize() {
	driveBae->setSpeed(backSlashSpeed, forwardSlashSpeed, forwardSlashSpeed,
			backSlashSpeed);
}

void TimedDrive::Execute() {
	//ayy lmao
}

bool TimedDrive::IsFinished() {
	return IsTimedOut();
}

void TimedDrive::End() {
	driveBae->setSpeed(0.0, 0.0, 0.0, 0.0);
}

void TimedDrive::Interrupted() {
	End();
}
