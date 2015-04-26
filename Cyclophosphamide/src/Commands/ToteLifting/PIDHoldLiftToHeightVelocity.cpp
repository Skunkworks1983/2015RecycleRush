#include "PIDHoldLiftToHeightVelocity.h"

PIDHoldLiftToHeightVelocity::PIDHoldLiftToHeightVelocity(double speed) {
	Requires(toteLifter);
	Requires(armWrist);
	this->speed = speed;
}

// Called just before this Command runs the first time
void PIDHoldLiftToHeightVelocity::Initialize() {
	if(speed > 0){
		armWrist->setWrist(DoubleSolenoid::Value::kReverse);
	}
	toteLifter->setMotorSpeed(speed);
}

// Called repeatedly when this Command is scheduled to run
void PIDHoldLiftToHeightVelocity::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool PIDHoldLiftToHeightVelocity::IsFinished() {
	return toteLifter->getEncoder()->PIDGet() >= TOTE_LIFTER_MAX_DISTANCE
			|| toteLifter->getEncoder()->PIDGet() < 16;
}

// Called once after isFinished returns true
void PIDHoldLiftToHeightVelocity::End() {
	toteLifter->enablePID(true);
	toteLifter->setSetPoints(toteLifter->getEncoder()->PIDGet());
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PIDHoldLiftToHeightVelocity::Interrupted() {
	End();
}
