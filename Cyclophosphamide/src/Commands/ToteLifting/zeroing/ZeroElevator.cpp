#include <Commands/ToteLifting/zeroing/ZeroElevator.h>

ZeroElevator::ZeroElevator() {
	Requires(toteLifterino);
	zeroCount = 0;
}

// Called just before this Command runs the first time
void ZeroElevator::Initialize() {
	toteLifterino->setMotorSpeed(-TOTE_LIFTER_ZERO_SPEED);
	oldEncoderTick = toteLifterino->getEncoder()->PIDGet();
}

// Called repeatedly when this Command is scheduled to run
void ZeroElevator::Execute() {
	//not tested, needs to be tested
	if (toteLifterino->getEncoder()->PIDGet() == oldEncoderTick) {
		toteLifterino->setMotorSpeed(-TOTE_LIFTER_ZERO_SPEED / (zeroCount)); //less and less motor power if it is zeroed
		zeroCount++;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ZeroElevator::IsFinished() {
	return zeroCount >= TOTE_LIFTER_COUNT_ZEROED;
}

// Called once after isFinished returns true
void ZeroElevator::End() {
	toteLifterino->getEncoder()->Reset();
	toteLifterino->setMotorSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ZeroElevator::Interrupted() {
}
