#include "OverrideGyro.h"

OverrideGyro::OverrideGyro(bool override)
{
	Requires(driveBase);
	this->override = override;
}

// Called just before this Command runs the first time
void OverrideGyro::Initialize()
{
	if(override) {
		driveBase->stopRotPID();
		driveBase->setGyroEnabled(false);
	} else {
		driveBase->setGyroEnabled(true);
		driveBase->zeroPIDOutput();
		driveBase->startRotPID();
	}
}

// Called repeatedly when this Command is scheduled to run
void OverrideGyro::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool OverrideGyro::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void OverrideGyro::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void OverrideGyro::Interrupted()
{

}
