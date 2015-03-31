#include "TimedTurn.h"

TimedTurn::TimedTurn(float timeout, float speed)
{
	Requires(driveBase);
	SetTimeout(timeout);
	this->speed = speed;
}

// Called just before this Command runs the first time
void TimedTurn::Initialize()
{
	driveBase->setClockwise(speed);
	driveBase->setForward(0.0);
	driveBase->setRight(0.0);
	driveBase->execute();
}

// Called repeatedly when this Command is scheduled to run
void TimedTurn::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool TimedTurn::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void TimedTurn::End()
{
	driveBase->setAll(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TimedTurn::Interrupted()
{
	End();
}
