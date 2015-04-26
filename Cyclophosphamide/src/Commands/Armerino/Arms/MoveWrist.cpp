#include <Commands/Armerino/Arms/MoveWrist.h>

MoveWrist::MoveWrist(State state, bool override) {
	Requires(armWrist);
	this->state = state;
	this->override = override;
	//setpoint = open ? DoubleSolenoid::kForward : DoubleSolenoid::kReverse;
}

void MoveWrist::Initialize() {
	switch (state) {
	case toggle:
		if (armWrist->getWristToggle()) {
			armWrist->setWrist(DoubleSolenoid::kForward);
		} else {
			armWrist->setWrist(DoubleSolenoid::kReverse);
		}
		armWrist->doTheToggleWrist();
		break;
	case open:
		// TODO is it sketchy to use two subsystems?
		armWrist->setWrist(DoubleSolenoid::kForward);
		break;
	case close:
		armWrist->setWrist(DoubleSolenoid::kReverse);
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
