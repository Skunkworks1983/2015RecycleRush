#include "CommandBase.h"
#include "Subsystems/DriveBase.h"
#include "Commands/Scheduler.h"
#include "Subsystems/StackPusher.h"

// Initialize a single static instance of all of your subsystems to NULL
DriveBase* CommandBase::driveBase = NULL;
OI* CommandBase::oi = NULL;
CanCollecterino* CommandBase::canCollecterino = NULL;
ToteIntakerino* CommandBase::toteIntakerino = NULL;
StackPusher* CommandBase::stackPusher = NULL;
ToteLifterino* CommandBase::toteLifterino = NULL;
Craaaw* CommandBase::craaaw = NULL;
CommandBase::CommandBase(char const *name) :
		Command(name) {
}

CommandBase::CommandBase() :
		Command() {

}

CommandBase::~CommandBase() {
	delete driveBase;
	delete canCollecterino;
	delete toteIntakerino;
	delete oi;
	delete stackPusher;
	delete craaaw;
}

void CommandBase::init() {
	driveBase = new DriveBase();
	canCollecterino = new CanCollecterino();
	toteIntakerino = new ToteIntakerino();
	toteLifterino = new ToteLifterino();
	oi = new OI();
	stackPusher = new StackPusher();
	craaaw = new Craaaw();
}
