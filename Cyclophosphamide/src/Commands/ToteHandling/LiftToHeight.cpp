#include "LiftToHeight.h"

LiftToHeight::LiftToHeight(double destination) :
		CommandBase("LiftToHeight") {
	Requires(toteLifterino);
	this->destination = destination;
	if (toteLifterino->isCoop() && destination != TOTE_LIFTER_FLOOR_HEIGHT) {
		destination += 4 * TOTE_INTAKE_TICKS_PER_INCH; //add 4 inches to the destination
	}
}

// Called just before this Command runs the first time
void LiftToHeight::Initialize() {
	toteLifterino->setSetPoints(destination);
	toteLifterino->enablePID(true);
}

// Called repeatedly when this Command is scheduled to run
void LiftToHeight::Execute() {
	//Nothing?
	SmartDashboard::PutNumber("Destination", destination);
}

// Make this return true when this Command no longer needs to run execute()
bool LiftToHeight::IsFinished() {
	//don't end when at destination because PID needs to hold the totes up until there is a tote underneath
	return toteLifterino->getPID()->OnTarget();
}

// Called once after isFinished returns true
void LiftToHeight::End() {
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftToHeight::Interrupted() {
}
