#include <Commands/ToteLifting/LiftToHeight.h>

LiftToHeight::LiftToHeight(double destination) :
		CommandBase("LiftToHeight") {
	Requires(toteLifterino);
	this->destination = destination;
	SetTimeout(TOTE_LIFTER_TIMEOUT);
}

// Called just before this Command runs the first time
void LiftToHeight::Initialize() {
	if (destination > toteLifterino->getEncoder()->PIDGet()
			&& toteLifterino->getCraaawInput()) {
		destination = toteLifterino->getEncoder()->PIDGet();
	}

	toteLifterino->setSetPoints(destination);
	toteLifterino->enablePID(true);
}

// Called repeatedly when this Command is scheduled to run
void LiftToHeight::Execute() {
	//Nothing?

	SmartDashboard::PutNumber("Destination", destination);

	if (destination == TOTE_LIFTER_FLOOR_HEIGHT
			&& toteLifterino->closeEnough(destination)) {
		toteLifterino->enablePID(false);
	}

}

// Make this return true when this Command no longer needs to run execute()
bool LiftToHeight::IsFinished() {
	//don't end when at destination because PID needs to hold the totes up until there is a tote underneath
	return (destination > TOTE_LIFTER_CARRY_HEIGHT
			&& toteLifterino->getCraaawInput());
	//return false;
}

// Called once after isFinished returns true
void LiftToHeight::End() {
	toteLifterino->setSetPoints(toteLifterino->getEncoder()->PIDGet());
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftToHeight::Interrupted() {
}
