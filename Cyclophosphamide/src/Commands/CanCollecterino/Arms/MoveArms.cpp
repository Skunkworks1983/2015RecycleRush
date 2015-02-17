#include <Commands/CanCollecterino/Arms/MoveArms.h>

MoveArms::MoveArms(bool up) {
	Requires(canCollecterino);
}

void MoveArms::Initialize() {
	if (canCollecterino->getToggleArms()) {
		setpoint = CAN_POT_UP_POSITION;
		canCollecterino->doTheToggleArms();
	} else {
		setpoint = CAN_POT_DOWN_POSITION;
		canCollecterino->doTheToggleArms();
	}
	canCollecterino->setArms(setpoint);
}

void MoveArms::Execute() {

}

bool MoveArms::IsFinished() {
	return canCollecterino->armsWithinBounds();
}

void MoveArms::End() {
	canCollecterino->disableArms();
}

void MoveArms::Interrupted() {
	canCollecterino->disableArms();
}
