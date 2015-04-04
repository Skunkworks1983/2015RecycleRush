#include <Commands/ToteLifting/LiftToHeight.h>

LiftToHeight::LiftToHeight(double destination) :
		CommandBase("LiftToHeight") {
	Requires(toteLifter);
	this->destination = destination;
}

// Called just before this Command runs the first time
void LiftToHeight::Initialize() {
	SmartDashboard::PutNumber("Destination START", destination);
	if (destination > toteLifter->getEncoder()->PIDGet()
			&& toteLifter->getCraaawInput() && destination != TOTE_LIFTER_CARRY_HEIGHT) {
		destination = toteLifter->getEncoder()->PIDGet();
	}

	toteLifter->setSetPoints(destination);
	toteLifter->enablePID(true);
}

// Called repeatedly when this Command is scheduled to run
void LiftToHeight::Execute() {
	//Nothing?

	SmartDashboard::PutNumber("Destination", destination);

	if (destination == TOTE_LIFTER_FLOOR_HEIGHT
			&& toteLifter->closeEnough(destination)) {
		toteLifter->enablePID(false);
	}	//TODO: remove this useless garbage

}

// Make this return true when this Command no longer needs to run execute()
bool LiftToHeight::IsFinished() {
	//don't end when at destination because PID needs to hold the totes up until there is a tote underneath
	return (destination > TOTE_LIFTER_CARRY_HEIGHT
			&& toteLifter->getCraaawInput());
	//return false;
}

// Called once after isFinished returns true
void LiftToHeight::End() {
	//toteLifterino->getPID()->Disable();
	toteLifter->setSetPoints(
			toteLifter->getEncoder()->PIDGet()
					+ (TOTE_LIFTER_TICKS_PER_INCH * .25));
	//toteLifterino->getPID()->Enable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftToHeight::Interrupted() {
}
