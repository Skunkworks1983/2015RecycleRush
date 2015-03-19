#include "EnableIntake.h"

EnableIntake::EnableIntake(bool enable)
{
	Requires(toteIntakerino);
	this->enable = enable;
}

// Called just before this Command runs the first time
void EnableIntake::Initialize()
{
	if(enable){
		toteIntakerino->getPID()->Enable();
	} else {
		toteIntakerino->getPID()->Disable();
	}
}

// Called repeatedly when this Command is scheduled to run
void EnableIntake::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool EnableIntake::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void EnableIntake::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void EnableIntake::Interrupted()
{

}
