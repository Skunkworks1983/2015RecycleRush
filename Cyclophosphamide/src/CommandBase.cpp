#include "CommandBase.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
DriveBase* CommandBase::driveBase = NULL;
OI* CommandBase::oi = NULL;
CanCollecterino* CommandBase::canCollecterino = NULL;
ToteIntakerino* CommandBase::tote_intakerino = NULL;
ToteLifterino* CommandBase::tote_lifterino = NULL;

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
	driveBase = new DriveBase();
	tote_intakerino = new ToteIntakerino();
	tote_lifterino = new ToteLifterino();
	oi = new OI();
}
