#include "PushStack.h"

PushStack::PushStack()
{
	Requires(stackPusher);// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void PushStack::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void PushStack::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool PushStack::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void PushStack::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PushStack::Interrupted()
{

}
