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
	// could cause a big problem with synchronization
	if (oi->checkStackFlag()) {
		toteLifterino->addDestination(TOTE_LIFTER_KEY_POS_0);
		toteLifterino->addDestination(TOTE_LIFTER_KEY_POS_3);
	}

	toteLifterino->driveTowardsDestination();
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
