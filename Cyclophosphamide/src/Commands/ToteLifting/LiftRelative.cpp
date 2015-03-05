#include <Commands/ToteLifting/LiftRelative.h>

LiftRelative::LiftRelative(float delta) {
	Requires(toteLifterino);
	this->delta = delta;
	this->destination = 0;
}

void LiftRelative::Initialize() {
	destination =
			toteLifterino->getPID()->GetSetpoint()+delta*TOTE_LIFTER_TICKS_PER_INCH;
	toteLifterino->setSetPoints(destination);
}

void LiftRelative::Execute() {
	SmartDashboard::PutNumber("Destination", destination);
	if (destination == TOTE_LIFTER_FLOOR_HEIGHT
			&& toteLifterino->closeEnough(destination)) {
		toteLifterino->enablePID(false);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool LiftRelative::IsFinished() {
	return toteLifterino->getPID()->OnTarget();
}

// Called once after isFinished returns true
void LiftRelative::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftRelative::Interrupted() {

}
