#include <Subsystems/ArmWristerino.h>
#include "../RobotMap.h"

ArmWristerino::ArmWristerino() :
		Subsystem("CanWristerino") {
	SAFE_INIT(CAN_WRIST_SOLENOID_PORT,
			wrists = new DoubleSolenoid(CAN_WRIST_SOLENOID_PORT););
	toggleWrist = true;
}

ArmWristerino::~ArmWristerino() {
	delete wrists;
}

void ArmWristerino::InitDefaultCommand() {

}

void ArmWristerino::setWrist(DoubleSolenoid::Value value) {
	wrists->Set(value);
}

void ArmWristerino::doTheToggleWrist() {
	if (toggleWrist) {
		toggleWrist = false;
	} else {
		toggleWrist = true;
	}
}

bool ArmWristerino::getWristToggle() {
	return toggleWrist;
}
