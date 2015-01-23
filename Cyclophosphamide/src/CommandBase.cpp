#include "CommandBase.h"
#include "Subsystems/DriveBase.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
DriveBase* CommandBase::driveBase = NULL;
OI* CommandBase::oi = NULL;
CanCollecterino* CommandBase::canCollecterino = NULL;

CommandBase::CommandBase(char const *name) :
		Command(name) {
}

CommandBase::CommandBase() :
		Command() {

}

CommandBase::~CommandBase() {
	delete driveBase;
	delete canCollecterino;
	delete oi;
}

void CommandBase::init() {
	driveBase = new DriveBase();
	canCollecterino = new CanCollecterino();
	oi = new OI();
}
