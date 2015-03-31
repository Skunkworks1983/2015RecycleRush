#include <Commands/ToteLifting/zeroing/ResetElevatorEncoder.h>

ResetElevatorEncoder::ResetElevatorEncoder() {
	Requires(toteLifter);
}

// Called just before this Command runs the first time
void ResetElevatorEncoder::Initialize() {

	/*
	 * Why would we ever want to zero the encoder unless it was below the previous value??
	 */
	if (toteLifter->getEncoder()->PIDGet() < 0) {
		toteLifter->getEncoder()->Reset();
	}
}

// Called repeatedly when this Command is scheduled to run
void ResetElevatorEncoder::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ResetElevatorEncoder::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ResetElevatorEncoder::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ResetElevatorEncoder::Interrupted() {

}
