#include <CommandBase.h>

// Initialize a single static instance of all of your subsystems to NULL
DriveBase* CommandBase::driveBase = NULL;
OI* CommandBase::oi = NULL;
ArmLifter* CommandBase::armLifter = NULL;
ArmWrist* CommandBase::armWrist = NULL;
ArmIntake* CommandBase::armIntake = NULL;
ToteIntake* CommandBase::toteIntake = NULL;
ToteLifter* CommandBase::toteLifter = NULL;
CanStabilizer* CommandBase::canStabilizer = NULL;
Pneumatics* CommandBase::pneumatics = NULL;
AutoCanGrabber* CommandBase::autoCanGrabber = NULL;

CommandBase::CommandBase(char const *name) :
		Command(name) {
}

CommandBase::CommandBase() :
		Command() {
}

CommandBase::~CommandBase() {
	delete driveBase;
	delete armLifter;
	delete armWrist;
	delete armIntake;
	delete toteIntake;
	delete toteLifter;
	delete oi;
	delete canStabilizer;
	delete pneumatics;
}

void CommandBase::init() {
	driveBase = new DriveBase();
	armLifter = new ArmLifter();
	armWrist = new ArmWrist();
	armIntake = new ArmIntake();
	toteIntake = new ToteIntake();
	toteLifter = new ToteLifter();
	oi = new OI();
	canStabilizer = new CanStabilizer();
	pneumatics = new Pneumatics();
	autoCanGrabber = new AutoCanGrabber();
}
