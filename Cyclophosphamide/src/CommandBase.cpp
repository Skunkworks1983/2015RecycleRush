#include "CommandBase.h"
#include "Subsystems/DriveBae.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
DriveBae* CommandBase::driveBae = NULL;
OI* CommandBase::oi = NULL;
CanCollecterino* CommandBase::canCollecterino = NULL;
CanWristerino* CommandBase::canWristerino = NULL;
CanIntakerino* CommandBase::canIntakerino = NULL;
ToteIntakerino* CommandBase::toteIntakerino = NULL;
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
	delete canWristerino;
	delete canIntakerino;
	delete toteIntakerino;
	delete toteLifterino;
	delete oi;
	delete craaaw;
	delete pneumatics;
}

void CommandBase::init() {
	driveBae = new DriveBae();
	canCollecterino = new CanCollecterino();
	canWristerino = new CanWristerino();
	canIntakerino = new CanIntakerino();
	toteIntakerino = new ToteIntakerino();
	toteLifterino = new ToteLifterino();
	oi = new OI();
	craaaw = new Craaaw();
	pneumatics = new Pneumatics();
}
