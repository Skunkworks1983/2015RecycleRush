#include "LiftToHeight.h"

LiftToHeight::LiftToHeight(double destination) :
		CommandBase("LiftToHeight") {
	Requires(toteLifterino);
	this->destination = destination;
}

// Called just before this Command runs the first time
void LiftToHeight::Initialize() {
	toteLifterino->setSetPoints(destination);
	toteLifterino->enablePID(true);
}

// Called repeatedly when this Command is scheduled to run
void LiftToHeight::Execute() {
	//Nothing?
	/* Leaving this in the code in case we need on the fly pid tuning for this subsystem or others. TODO: remove when unneeded*/
	if (count++ > 25) {
		if (toteLifterino->getPID()->GetP() != SmartDashboard::GetNumber("P")) {
			toteLifterino->getPID()->SetPID(SmartDashboard::GetNumber("P"),
					toteLifterino->getPID()->GetI(),
					toteLifterino->getPID()->GetD());
		}
		if (toteLifterino->getPID()->GetI() != SmartDashboard::GetNumber("I")) {
			toteLifterino->getPID()->SetPID(toteLifterino->getPID()->GetP(),
					SmartDashboard::GetNumber("I"),
					toteLifterino->getPID()->GetD());
		}
		if (toteLifterino->getPID()->GetD() != SmartDashboard::GetNumber("D")) {
			toteLifterino->getPID()->SetPID(toteLifterino->getPID()->GetP(),
					toteLifterino->getPID()->GetI(),
					SmartDashboard::GetNumber("D"));
		}
	}

	/*if (toteLifterino->getEncoder()->Get() < destination + TOTE_LIFTER_TOLERANCE
	 || toteLifterino->getEncoder()->Get()
	 > destination - TOTE_LIFTER_TOLERANCE) {
	 count++;
	 }*/
	SmartDashboard::PutNumber("Destination", destination);
}

// Make this return true when this Command no longer needs to run execute()
bool LiftToHeight::IsFinished() {
	//don't end when at destination because PID needs to hold the totes up until there is a tote underneath
	return false;
	//return toteLifterino->getPID()->OnTarget();
	// return toteLifterino->getElevatorDigitalInput() && destination < 0
	// return toteLifterino->isToteUnder();
}

// Called once after isFinished returns true
void LiftToHeight::End() {
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftToHeight::Interrupted() {
	//toteLifterino->setSetPoints(toteLifterino->getEncoder()->GetDistance());
}
