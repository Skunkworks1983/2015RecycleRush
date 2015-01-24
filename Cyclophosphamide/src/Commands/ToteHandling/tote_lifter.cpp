#include "tote_lifter.h"

tote_lifter::tote_lifter()
{
	Requires(toteLifterino);
}

// Called just before this Command runs the first time
void tote_lifter::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void tote_lifter::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool tote_lifter::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void tote_lifter::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void tote_lifter::Interrupted()
{

}
