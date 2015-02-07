#include <Commands/CanCollecterino/Arms/MoveArms.h>

MoveArms::MoveArms(bool up) {
	if (up) {
		setpoint = CAN_POT_UP_POSITION;
	} else {
		setpoint = CAN_POT_DOWN_POSITION;
	}
}

void MoveArms::Initialize() {
	canCollecterino->setArms(setpoint);
	Requires(canCollecterino);
}

void MoveArms::Execute() {

}

bool MoveArms::IsFinished() {
	return canCollecterino->armsWithinBounds(setpoint, CAN_LIFT_THRESHOLD);
}

void MoveArms::End() {
	canCollecterino->disableArms();
}

void MoveArms::Interrupted() {

}
