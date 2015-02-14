#include "CommandBase.h"
#include "Subsystems/DriveBae.h"
#include "Commands/Scheduler.h"
#include "Subsystems/StackPusher.h"

// Initialize a single static instance of all of your subsystems to NULL
DriveBae* CommandBase::driveBae = NULL;
OI* CommandBase::oi = NULL;
CanCollecterino* CommandBase::canCollecterino = NULL;
ToteIntakerino* CommandBase::toteIntakerino = NULL;
StackPusher* CommandBase::stackPusher = NULL;
ToteLifterino* CommandBase::toteLifterino = NULL;
Craaaw* CommandBase::craaaw = NULL;
Pneumatics* CommandBase::pneumatics = NULL;

CommandBase::CommandBase(char const *name) :
		Command(name) {
}

CommandBase::CommandBase() :
		Command() {

}

CommandBase::~CommandBase() {
	delete driveBae;
	delete canCollecterino;
	delete toteIntakerino;
	delete toteLifterino;
	delete oi;
	delete stackPusher;
	delete craaaw;
	delete pneumatics;
}

void CommandBase::init() {
	driveBae = new DriveBae();
	canCollecterino = new CanCollecterino();
//	toteIntakerino = new ToteIntakerino();
//	toteLifterino = new ToteLifterino();
	oi = new OI();
//	stackPusher = new StackPusher();
//	craaaw = new Craaaw();
	pneumatics = new Pneumatics();
}
