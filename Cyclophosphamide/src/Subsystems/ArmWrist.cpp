#include <Subsystems/ArmWrist.h>
#include "../RobotMap.h"

ArmWrist::ArmWrist() :
		Subsystem("CanWristerino") {
	SAFE_INIT(CAN_WRIST_SOLENOID_PORT,
			wrists = new DoubleSolenoid(CAN_WRIST_SOLENOID_PORT););
	toggleWrist = true;
}

ArmWrist::~ArmWrist() {
	delete wrists;
}

void ArmWrist::InitDefaultCommand() {

}

void ArmWrist::setWrist(DoubleSolenoid::Value value) {
	if (value == DoubleSolenoid::kForward) {
		toggleWrist = true;
	} else {
		toggleWrist = false;
	}
	wrists->Set(value);
}

void ArmWrist::doTheToggleWrist() {
	if (toggleWrist) {
		toggleWrist = false;
	} else {
		toggleWrist = true;
	}
}

bool ArmWrist::getWristToggle() {
	return toggleWrist;
}
