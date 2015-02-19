#include <Commands/CanCollecterino/Arms/MoveArms.h>

MoveArms::MoveArms(float setpoint) {
	Requires(canCollecterino);
	this->setpoint = setpoint;
}

void MoveArms::Initialize() {
	canCollecterino->setArms(setpoint);
}

void MoveArms::Execute() {

}

bool MoveArms::IsFinished() {
	return canCollecterino->armsWithinBounds();
}

void MoveArms::End() {
	if (setpoint == CAN_POT_KNOCK) {
		canCollecterino->disableArms();
	}
}

void MoveArms::Interrupted() {
	canCollecterino->disableArms();
}
