#include "ToggleCoop.h"

ToggleCoop::ToggleCoop() {
	Requires(toteLifterino);
}

// Called just before this Command runs the first time
void ToggleCoop::Initialize() {
	toteLifterino->setCoop(!toteLifterino->isCoop());
}

// Called repeatedly when this Command is scheduled to run
void ToggleCoop::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ToggleCoop::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ToggleCoop::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleCoop::Interrupted() {

}
