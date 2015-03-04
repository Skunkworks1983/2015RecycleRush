#include <Commands/ToteHandling/DownUp.h>

DownUp::DownUp(Position pos) :
		CommandBase("DownUp") {
	Requires(toteLifterino);
	this->pos = pos;
	destination = TOTE_LIFTER_CARRY_HEIGHT;
	SetTimeout(TOTE_LIFTER_TIMEOUT);
}

// Called just before this Command runs the first time
void DownUp::Initialize() {
	if (toteLifterino->getPID()->GetSetpoint() > TOTE_LIFTER_FLOOR_HEIGHT) {
		destination = TOTE_LIFTER_FLOOR_HEIGHT;
	} else {
		switch (pos) {
		case carry:
			destination = TOTE_LIFTER_CARRY_HEIGHT;
			break;
		case load:
			destination = TOTE_LIFTER_LOAD_HEIGHT;
			break;
		}
	}

	SmartDashboard::PutNumber("Coop destination", -1);
	toteLifterino->setSetPoints(destination);
	toteLifterino->enablePID(true);
}

// Called repeatedly when this Command is scheduled to run
void DownUp::Execute() {
	SmartDashboard::PutNumber("Destination", destination);

	if (destination == TOTE_LIFTER_FLOOR_HEIGHT
			&& toteLifterino->closeEnough(destination)) {
		toteLifterino->enablePID(false);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DownUp::IsFinished() {
	return toteLifterino->getPID()->OnTarget()
			|| toteLifterino->closeEnough(destination) || IsTimedOut();
}

// Called once after isFinished returns true
void DownUp::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DownUp::Interrupted() {

}
