#include "ResetGyro.h"

ResetGyro::ResetGyro()
{
	Requires(driveBase);
	firstIteration = true;
}

void ResetGyro::Initialize()
{
	firstIteration = true;
}

void ResetGyro::Execute()
{
	if(firstIteration){
		bool is_calibrating = driveBase->getGyro()->IsCalibrating();
		if ( !is_calibrating ) {
			Wait( 0.3 );
			driveBase->getGyro()->ZeroYaw();
			firstIteration = false;
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ResetGyro::IsFinished()
{
	return !firstIteration;
}

// Called once after isFinished returns true
void ResetGyro::End()
{
	driveBase->setTargetAngle(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ResetGyro::Interrupted()
{
	driveBase->setTargetAngle(0.0);
}
