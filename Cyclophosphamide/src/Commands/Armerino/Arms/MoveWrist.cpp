#include <Commands/Armerino/Arms/MoveWrist.h>

MoveWrist::MoveWrist(State state) {
	Requires(armWristerino);
	this->state = state;
	//setpoint = open ? DoubleSolenoid::kForward : DoubleSolenoid::kReverse;
}

void MoveWrist::Initialize() {
	switch (state) {
	case toggle:
		if (armWristerino->getWristToggle()) {
			armWristerino->setWrist(DoubleSolenoid::kForward);
		} else {
			armWristerino->setWrist(DoubleSolenoid::kReverse);
		}
		armWristerino->doTheToggleWrist();
		break;
	case open:
		armWristerino->setWrist(DoubleSolenoid::kForward);
		break;
	case close:
		armWristerino->setWrist(DoubleSolenoid::kReverse);
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
