#include "ResetLifterEncoder.h"

ResetLifterEncoder::ResetLifterEncoder()
{
	Requires(toteLifterino);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ResetLifterEncoder::Initialize()
{
	toteLifterino->getEncoder()->Reset();
}

// Called repeatedly when this Command is scheduled to run
void ResetLifterEncoder::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ResetLifterEncoder::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ResetLifterEncoder::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ResetLifterEncoder::Interrupted()
{

}
