#include "Craaaw.h"
#include "../RobotMap.h"
#include "../Commands/MecanumDrive.h"
#include <cmath>
#include "../Commands/CanCollecterino/Craaaw/CraaawActuate.h"

Craaaw::Craaaw() :
		Subsystem("Craaaw") {
	SAFE_INIT(CRAAAW_CAN_DETECTOR, canDetector = new DigitalInput(CRAAAW_CAN_DETECTOR););
	SAFE_INIT(CRAAAW_LOCK_LEFT, craaawLocker = new DoubleSolenoid(CRAAAW_LOCK_LEFT, CRAAAW_LOCK_RIGHT););
	stateOpen = true;
}

Craaaw::~Craaaw() {
	delete canDetector;
	delete craaawLocker;
}

void Craaaw::InitDefaultCommand() {
	SetDefaultCommand(new CraaawActuate());
}

bool Craaaw::getCanDetector() {
	return canDetector->Get();
}

void Craaaw::toggle() {
	if (stateOpen) {
		craaawLocker->Set(DoubleSolenoid::kForward);
		stateOpen = false;
	} else {
		craaawLocker->Set(DoubleSolenoid::kReverse);
		stateOpen = true;
	}
}

