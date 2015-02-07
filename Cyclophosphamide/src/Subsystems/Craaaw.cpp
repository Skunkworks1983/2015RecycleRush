#include "Craaaw.h"
#include "../RobotMap.h"
#include "../Commands/Drivebase/MecanumDrive.h"
#include <cmath>
#include "../Commands/CanCollecterino/Craaaw/CraaawActuate.h"
Craaaw::Craaaw() :
		Subsystem("Craaaw") {
	SAFE_INIT(CRAAAW_CAN_DETECTOR,
			canDetector = new DigitalInput(CRAAAW_CAN_DETECTOR););
	SAFE_INIT(CRAAAW_LOCK_LEFT,
			craaawLocker = new DoubleSolenoid(CRAAAW_LOCK_LEFT, CRAAAW_LOCK_RIGHT););
	isActuated = true;
}
Craaaw::~Craaaw() {
	delete canDetector;
	delete craaawLocker;
}
void Craaaw::InitDefaultCommand() {
	SetDefaultCommand(new CraaawActuate(true));
}
bool Craaaw::getCanDetector() {
	return canDetector->Get();
}
void Craaaw::setActuated(bool actuate) {
	if (!actuate) {
		craaawLocker->Set(DoubleSolenoid::kForward);
	} else {
		craaawLocker->Set(DoubleSolenoid::kReverse);
	}
	isActuated = actuate;
}
