#include <Commands/Drivebase/ScoreLineup.h>

ScoreLineup::ScoreLineup() { // This is all assuming
	Requires(driveBae);
}

void ScoreLineup::Initialize() {
	driveBae->setModeAll(CANSpeedController::kSpeed);
	driveBae->setPIDAll(0.5, 0, 0);
	driveBae->setSetpoint(0.5);
	driveBae->enablePIDAll(true);
}

void ScoreLineup::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ScoreLineup::IsFinished() {
	return driveBae->getLightSensor();
}

// Called once after isFinished returns true
void ScoreLineup::End() {
	driveBae->setAll(0);
	driveBae->enablePIDAll(false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ScoreLineup::Interrupted() {
	driveBae->setAll(0);
	driveBae->enablePIDAll(false);
}
