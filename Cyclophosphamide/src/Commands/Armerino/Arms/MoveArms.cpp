#include <Commands/Armerino/Arms/MoveArms.h>

MoveArms::MoveArms(float setpoint) {
	Requires(armLifter);
	this->setpoint = setpoint;
	SetTimeout(3);
}

void MoveArms::Initialize() {
	if (armLifter->getSetpoint() == CAN_POT_KNOCK_POSITION) {
		armLifter->setArms(CAN_POT_UP_POSITION);
	} else {
		armLifter->setArms(setpoint);
	}
}

void MoveArms::Execute() {
	if (setpoint == CAN_POT_DOWN_POSITION) {
		if (CommandBase::driveBae->getGyro()->GetPitch() >= ARMS_ARE_BREAKING_PITCH_THRESHOLD) {
			//if the arms are pushing the robot up
			setpoint = CAN_POT_UP_POSITION;
			armLifter->setArms(setpoint);
		}
	}
}

bool MoveArms::IsFinished() {
	return armLifter->armsWithinBounds() || IsTimedOut();
}

void MoveArms::End() {

}

void MoveArms::Interrupted() {
	armLifter->disableArms();
}
