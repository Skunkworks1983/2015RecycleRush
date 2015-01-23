#include "CommandBase.h"
#include "Subsystems/DriveBase.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
DriveBase* CommandBase::driveBase = NULL;
OI* CommandBase::oi = NULL;
CanCollecterino* CommandBase::canCollecterino = NULL;
ToteIntakerino CommandBase::tote_intakerino = NULL;
CommandBase::CommandBase(char const *name) :
		Command(name) {
}

CommandBase::CommandBase() :
		Command() {

}

CommandBase::~CommandBase() {
	delete driveBase;
	delete canCollecterino;
	delete tote_intakerino;
	delete oi;
}

void CommandBase::init() {
	driveBase = new DriveBase();
	canCollecterino = new CanCollecterino();
	tote_intakerino = new ToteIntakerino();
	oi = new OI();
}
