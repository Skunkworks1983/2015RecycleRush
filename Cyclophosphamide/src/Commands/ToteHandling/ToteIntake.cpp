#include <Commands/ToteHandling/ToteIntake.h>

ToteIntake::ToteIntake()
{
	Requires(toteIntakerino);
}

// Called just before this Command runs the first time
void ToteIntake::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
// Make this return true when this Command no longer needs to run execute()
void ToteIntake::Execute()
{
	toteIntakerino->runIfTote();
}

// Make this return true when this Command no longer needs to run execute()
bool ToteIntake::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ToteIntake::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToteIntake::Interrupted()
{

}
