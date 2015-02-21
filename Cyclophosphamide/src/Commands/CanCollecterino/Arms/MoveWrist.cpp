#include <Commands/CanCollecterino/Arms/MoveWrist.h>

MoveWrist::MoveWrist(bool open) {
	Requires(canCollecterino);
	//setpoint = open ? DoubleSolenoid::kForward : DoubleSolenoid::kReverse;
}

void MoveWrist::Initialize() {
	canCollecterino->setWrist(setpoint);
	if (canCollecterino->getWristToggle()) {
		setpoint = DoubleSolenoid::kForward;
	} else {
		setpoint = DoubleSolenoid::kReverse;
	}
	canCollecterino->doTheToggleWrist();
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
