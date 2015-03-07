#include "CanWristerino.h"
#include "../RobotMap.h"

CanWristerino::CanWristerino() :
		Subsystem("CanWristerino") {
	SAFE_INIT(CAN_WRIST_SOLENOID_PORT,
			wrists = new DoubleSolenoid(CAN_WRIST_SOLENOID_PORT););
	toggleWrist = true;
}

CanWristerino::~CanWristerino() {
	delete wrists;
}

void CanWristerino::InitDefaultCommand() {

}

void CanWristerino::setWrist(DoubleSolenoid::Value value) {
	wrists->Set(value);
}

void CanWristerino::doTheToggleWrist() {
	if (toggleWrist) {
		toggleWrist = false;
	} else {
		toggleWrist = true;
	}
}

bool CanWristerino::getWristToggle() {
	return toggleWrist;
}
