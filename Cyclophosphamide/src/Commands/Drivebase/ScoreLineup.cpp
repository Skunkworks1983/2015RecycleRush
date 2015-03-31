#include <Commands/Drivebase/ScoreLineup.h>

ScoreLineup::ScoreLineup() { // This is all assuming
	Requires(driveBase);
}

void ScoreLineup::Initialize() {
	driveBase->setModeAll(CANSpeedController::kSpeed);
	driveBase->setPIDAll(0.5, 0, 0);
	driveBase->setSetpoint(0.5);
	driveBase->enablePIDAll(true);
}

void ScoreLineup::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ScoreLineup::IsFinished() {
	return driveBase->getLightSensor();
}

// Called once after isFinished returns true
void ScoreLineup::End() {
	driveBase->setAll(0);
	driveBase->enablePIDAll(false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ScoreLineup::Interrupted() {
	driveBase->setAll(0);
	driveBase->enablePIDAll(false);
}
