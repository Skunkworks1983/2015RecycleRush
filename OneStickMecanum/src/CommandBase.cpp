#include "CommandBase.h"
#include "Subsystems/DriveBase.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
DriveBae* CommandBase::driveBase = NULL;
OI* CommandBase::oi = NULL;

CommandBase::CommandBase(char const *name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

CommandBase::~CommandBase() {
	delete driveBase;
	delete oi;
}

void CommandBase::init()
{
	driveBase = new DriveBae();

	oi = new OI();
}
