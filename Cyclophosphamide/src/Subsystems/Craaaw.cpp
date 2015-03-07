#include "Craaaw.h"
#include "../RobotMap.h"
#include "../Commands/Drivebase/MecanumDrive.h"
#include <cmath>
#include "../Commands/CanCollecterino/Craaaw/CraaawActuate.h"
Craaaw::Craaaw() :
		Subsystem("Craaaw") {
	SAFE_INIT(CRAAAW_LOCK_LEFT_PORT,
			craaawLocker = new DoubleSolenoid(CRAAAW_LOCK_LEFT_PORT, CRAAAW_LOCK_RIGHT_PORT););
	isActuated = true;
}
Craaaw::~Craaaw() {
	delete craaawLocker;
}

void Craaaw::setActuated(DoubleSolenoid::Value value) {
	craaawLocker->Set(value);
}
