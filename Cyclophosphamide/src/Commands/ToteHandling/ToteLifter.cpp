#include <Commands/ToteHandling/ToteLifter.h>

ToteLifter::ToteLifter()
{
	Requires(toteLifterino);
}

// Called just before this Command runs the first time
void ToteLifter::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ToteLifter::Execute()
{
	// could cause a big problem with synchronization
	if (oi->checkStackFlag()) {
		toteLifterino->addDestination(TOTE_LIFTER_KEY_POS_0);
		toteLifterino->addDestination(TOTE_LIFTER_KEY_POS_3);
	}

	toteLifterino->driveTowardsDestination();
}

// Make this return true when this Command no longer needs to run execute()
bool ToteLifter::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ToteLifter::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToteLifter::Interrupted()
{

}
