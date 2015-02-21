#include <Commands/CanCollecterino/Arms/MoveWrist.h>

MoveWrist::MoveWrist(State state) {
	Requires(canCollecterino);
	this->state = state;
	//setpoint = open ? DoubleSolenoid::kForward : DoubleSolenoid::kReverse;
}

void MoveWrist::Initialize() {
	switch (state) {
	case toggle:
		if (canCollecterino->getWristToggle()) {
			canCollecterino->setWrist(DoubleSolenoid::kForward);
		} else {
			canCollecterino->setWrist(DoubleSolenoid::kReverse);
		}
		canCollecterino->doTheToggleWrist();
		break;
	case open:
		canCollecterino->setWrist(DoubleSolenoid::kForward);
		break;
	case close:
		canCollecterino->setWrist(DoubleSolenoid::kReverse);
		break;
	}
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
