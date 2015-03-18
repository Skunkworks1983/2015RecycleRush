#include <CommandBase.h>

// Initialize a single static instance of all of your subsystems to NULL
DriveBae* CommandBase::driveBae = NULL;
OI* CommandBase::oi = NULL;
ArmLifter* CommandBase::armLifter = NULL;
ArmWristerino* CommandBase::armWristerino = NULL;
ArmIntakerino* CommandBase::armIntakerino = NULL;
OldToteIntakerino* CommandBase::oldToteIntakerino = NULL;
NewToteIntakerino* CommandBase::newToteIntakerino = NULL;
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
	delete armLifter;
	delete armWristerino;
	delete armIntakerino;
	delete oldToteIntakerino;
	delete newToteIntakerino;
	delete toteLifterino;
	delete oi;
	delete craaaw;
	delete pneumatics;
}

void CommandBase::init() {
	driveBae = new DriveBae();
	armLifter = new ArmLifter();
	armWristerino = new ArmWristerino();
	armIntakerino = new ArmIntakerino();
	//newToteIntakerino = new NewToteIntakerino();
	oldToteIntakerino = new OldToteIntakerino();
	toteLifterino = new ToteLifterino();
	oi = new OI();
	craaaw = new Craaaw();
	pneumatics = new Pneumatics();
}
