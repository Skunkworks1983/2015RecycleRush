#include "ToggleWhackMode.h"

ToggleWhackMode::ToggleWhackMode() {
	Requires(canCollecterino);
	SetTimeout(CAN_KNOCK_TIMEOUT);
}

// Called just before this Command runs the first time
void ToggleWhackMode::Initialize() {
	if (canCollecterino->getArmPID()->GetSetpoint() == CAN_POT_KNOCK_POSITION) {
		canCollecterino->setArms(CAN_POT_UP_POSITION);
	} else {
		canCollecterino->setArms(CAN_POT_KNOCK_POSITION);
	}
}

// Called repeatedly when this Command is scheduled to run
void ToggleWhackMode::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ToggleWhackMode::IsFinished() {
	return canCollecterino->armsWithinBounds() || IsTimedOut();
}

// Called once after isFinished returns true
void ToggleWhackMode::End() {
	if (canCollecterino->getArmPID()->GetSetpoint() == CAN_POT_KNOCK_POSITION) {
		canCollecterino->disableArms();
	}
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleWhackMode::Interrupted() {
	canCollecterino->disableArms();
}
