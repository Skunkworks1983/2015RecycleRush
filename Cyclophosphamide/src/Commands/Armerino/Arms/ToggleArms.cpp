#include <Commands/Armerino/Arms/ToggleArms.h>

ToggleArms::ToggleArms() {
	Requires(armLifter);
}

// Called just before this Command runs the first time
void ToggleArms::Initialize() {
	if (armLifter->getSetpoint() == CAN_POT_UP_POSITION) {
		armLifter->setArms(CAN_POT_DOWN_POSITION);
	} else {
		armLifter->setArms(CAN_POT_UP_POSITION);
	}
}

// Called repeatedly when this Command is scheduled to run
void ToggleArms::Execute() {
	// Meh
}

// Make this return true when this Command no longer needs to run execute()
bool ToggleArms::IsFinished() {
	return armLifter->armsWithinBounds();
}

// Called once after isFinished returns true
void ToggleArms::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleArms::Interrupted() {
	armLifter->disableArms();
}
