#include <Commands/Drivebase/ZeroGyro.h>

ZeroGyro::ZeroGyro()
{
	Requires(driveBae);
	firstIteration = true;
}

void ZeroGyro::Initialize()
{
	firstIteration = true;
}

void ZeroGyro::Execute()
{
	if(firstIteration){
		bool is_calibrating = driveBae->getGyro()->IsCalibrating();
		if ( !is_calibrating ) {
			Wait( 0.3 );
			driveBae->getGyro()->ZeroYaw();
			firstIteration = false;
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ZeroGyro::IsFinished()
{
	return !firstIteration;
}

// Called once after isFinished returns true
void ZeroGyro::End()
{
	driveBae->setTargetAngle(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ZeroGyro::Interrupted()
{
	driveBae->setTargetAngle(0.0);
}
