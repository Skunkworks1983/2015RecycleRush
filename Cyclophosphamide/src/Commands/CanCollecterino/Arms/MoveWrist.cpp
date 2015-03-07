#include <Commands/CanCollecterino/Arms/MoveWrist.h>

MoveWrist::MoveWrist(State state) {
	Requires(canWristerino);
	this->state = state;
	//setpoint = open ? DoubleSolenoid::kForward : DoubleSolenoid::kReverse;
}

void MoveWrist::Initialize() {
	switch (state) {
	case toggle:
		if (canWristerino->getWristToggle()) {
			canWristerino->setWrist(DoubleSolenoid::kForward);
		} else {
			canWristerino->setWrist(DoubleSolenoid::kReverse);
		}
		canWristerino->doTheToggleWrist();
		break;
	case open:
		canWristerino->setWrist(DoubleSolenoid::kForward);
		break;
	case close:
		canWristerino->setWrist(DoubleSolenoid::kReverse);
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
