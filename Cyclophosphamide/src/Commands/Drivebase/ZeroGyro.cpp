#include <Commands/Drivebase/ZeroGyro.h>

ZeroGyro::ZeroGyro() {
	Requires(driveBase);
	firstIteration = true;
}

void ZeroGyro::Initialize() {
	firstIteration = true;
}

void ZeroGyro::Execute() {
	if (firstIteration) {
		bool is_calibrating = driveBase->getGyro()->IsCalibrating();
		if (!is_calibrating) {
			Wait(0.3);
			driveBase->getGyro()->ZeroYaw();
			firstIteration = false;
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ZeroGyro::IsFinished() {
	return !firstIteration;
}

// Called once after isFinished returns true
void ZeroGyro::End() {
	driveBase->setTargetAngle(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ZeroGyro::Interrupted() {
	driveBase->setTargetAngle(0.0);
}
