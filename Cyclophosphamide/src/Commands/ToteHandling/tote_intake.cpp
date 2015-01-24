#include <Commands/ToteHandling/tote_intake.h>

tote_intake::tote_intake()
{
	Requires(tote_intakerino);
}

// Called just before this Command runs the first time
void tote_intake::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void tote_intake::Execute()
{
	tote_intakerino->runIfTote();
}

// Make this return true when this Command no longer needs to run execute()
bool tote_intake::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void tote_intake::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void tote_intake::Interrupted()
{

}
