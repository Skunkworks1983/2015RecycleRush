#include <Commands/CanCollecterino/Arms/MoveArms.h>

MoveArms::MoveArms(float setpoint) {
	Requires(canCollecterino);
	this->setpoint = setpoint;
}

void MoveArms::Initialize() {
	if(canCollecterino->getSetpoint() == CAN_POT_KNOCK_POSITION) {
		canCollecterino->setArms(CAN_POT_UP_POSITION);
	} else {
		canCollecterino->setArms(setpoint);
	}
}

void MoveArms::Execute() {
	if (setpoint == CAN_POT_DOWN_POSITION) {
		if (CommandBase::driveBae->getGyro()->GetPitch() >= ARMS_ARE_BREAKING_PITCH_THRESHOLD) {
			//if the arms are pushing the robot up
			setpoint = CAN_POT_UP_POSITION;
			canCollecterino->setArms(setpoint);
		}
	}
}

bool MoveArms::IsFinished() {
	return canCollecterino->armsWithinBounds();
}

void MoveArms::End() {

}

void MoveArms::Interrupted() {
	canCollecterino->disableArms();
}
