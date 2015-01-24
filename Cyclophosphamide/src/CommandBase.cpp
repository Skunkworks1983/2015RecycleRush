#include "CommandBase.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
DriveBase* CommandBase::driveBase = NULL;
OI* CommandBase::oi = NULL;
CanCollecterino* CommandBase::canCollecterino = NULL;
ToteIntakerino* CommandBase::toteIntakerino = NULL;
ToteLifterino* CommandBase::toteLifterino = NULL;

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
	delete canCollecterino;
	delete toteIntakerino;
	delete toteLifterino;
}

void CommandBase::init()
{
	canCollecterino = new CanCollecterino();
	driveBase = new DriveBase();
	toteIntakerino = new ToteIntakerino();
	toteLifterino = new ToteLifterino();
	oi = new OI();
}
