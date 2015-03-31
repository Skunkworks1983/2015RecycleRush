#include <CommandBase.h>
#include <Commands/Subsystem.h>
#include <DoubleSolenoid.h>
#include <RobotMap.h>
#include <Subsystems/CanStabilizer.h>

CanStabilizer::CanStabilizer() :
		Subsystem("CanStabilizer") {
	SAFE_INIT(CRAAAW_LOCK_LEFT_PORT,
			craaawLocker = new DoubleSolenoid(CRAAAW_LOCK_LEFT_PORT, CRAAAW_LOCK_RIGHT_PORT););
	isActuated = true;
}
CanStabilizer::~CanStabilizer() {
	delete craaawLocker;
}

void CanStabilizer::setActuated(DoubleSolenoid::Value value) {
	isActuated = value == DoubleSolenoid::Value::kForward ? true : false;
	craaawLocker->Set(value);
}

bool CanStabilizer::isOpen() {
	return isActuated;
}
