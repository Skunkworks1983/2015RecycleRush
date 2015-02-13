#include <Commands/CanCollecterino/Arms/MoveWrist.h>

MoveWrist::MoveWrist(bool open) {
	if (open) {
		setpoint = DoubleSolenoid::kForward;
	} else {
		setpoint = DoubleSolenoid::kReverse;
	}
	Requires(canCollecterino);
}

void MoveWrist::Initialize() {
	canCollecterino->setWrist(setpoint);
}

void MoveWrist::Execute() {

}

bool MoveWrist::IsFinished() {
	return true;
}

void MoveWrist::End() {
}

void MoveWrist::Interrupted() {

}
