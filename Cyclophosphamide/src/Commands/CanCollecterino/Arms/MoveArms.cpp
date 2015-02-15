#include <Commands/CanCollecterino/Arms/MoveArms.h>

MoveArms::MoveArms(bool up) {
	int PIDChange = 0;
	if (up) {
		setpoint = CAN_POT_UP_POSITION - .3;
	} else {
		setpoint = CAN_POT_DOWN_POSITION + .3;
	}
	Requires(canCollecterino);
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
	canCollecterino->disableArms();
}

void MoveArms::Interrupted() {
	canCollecterino->disableArms();
}
