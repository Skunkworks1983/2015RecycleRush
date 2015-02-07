#include <Commands/CanCollecterino/Arms/MoveWrist.h>

MoveWrist::MoveWrist(bool open) {
	if (open) {
		setpoint = CAN_WRIST_OPEN_POSITION;
	} else {
		setpoint = CAN_WRIST_CLOSE_POSITION;
	}
}

void MoveWrist::Initialize() {
	canCollecterino->setWrist(CAN_WRIST_SPEED);
	Requires(canCollecterino);
}

void MoveWrist::Execute() {

}

bool MoveWrist::IsFinished() {
	return canCollecterino->wristWithinBounds(setpoint, CAN_WRIST_THRESHOLD);
}

void MoveWrist::End() {
	canCollecterino->setWrist(0);
}

void MoveWrist::Interrupted() {

}
