#include "UpdateCompressor.h"

UpdateCompressor::UpdateCompressor() :
	CommandBase("UpdateCompressor")
{
	Requires(pneumatics);
}

// Called just before this Command runs the first time
void UpdateCompressor::Initialize()
{
	ticksSinceUpdate = 0;
}

// Called repeatedly when this Command is scheduled to run
void UpdateCompressor::Execute()
{
	if (ticksSinceUpdate > 10) {
		bool state = pneumatics->isBelowPressure();
		pneumatics->setState(state);
		ticksSinceUpdate = 0;
	}
	++ticksSinceUpdate;
}

// Make this return true when this Command no longer needs to run execute()
bool UpdateCompressor::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void UpdateCompressor::End()
{
	pneumatics->setState(false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void UpdateCompressor::Interrupted()
{
	End();
}
