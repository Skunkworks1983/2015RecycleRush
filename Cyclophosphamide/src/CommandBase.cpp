#include <CommandBase.h>

// Initialize a single static instance of all of your subsystems to NULL
DriveBae* CommandBase::driveBae = NULL;
OI* CommandBase::oi = NULL;
ArmLifter* CommandBase::armLifter = NULL;
ArmWristerino* CommandBase::armWristerino = NULL;
ArmIntakerino* CommandBase::armIntakerino = NULL;
ToteIntakerino* CommandBase::toteIntakerino = NULL;
ToteLifterino* CommandBase::toteLifterino = NULL;
Craaaw* CommandBase::craaaw = NULL;
Pneumatics* CommandBase::pneumatics = NULL;
AutoCanGrabber* CommandBase::autoCanGrabber = NULL;

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
	delete toteIntakerino;
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
	toteIntakerino = new ToteIntakerino();
	toteLifterino = new ToteLifterino();
	oi = new OI();
	craaaw = new Craaaw();
	pneumatics = new Pneumatics();
	autoCanGrabber = new AutoCanGrabber();
}
