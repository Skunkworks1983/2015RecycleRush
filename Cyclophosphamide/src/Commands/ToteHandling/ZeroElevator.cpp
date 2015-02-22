#include "ZeroElevator.h"

ZeroElevator::ZeroElevator(bool zeroAtBottom) {
	Requires(toteLifterino);
	this->zeroAtBottom = zeroAtBottom;
}

// Called just before this Command runs the first time
void ZeroElevator::Initialize() {
	toteLifterino->setMotorSpeed(
			zeroAtBottom ? -TOTE_LIFTER_ZERO_SPEED : TOTE_LIFTER_ZERO_SPEED);
}

// Called repeatedly when this Command is scheduled to run
void ZeroElevator::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ZeroElevator::IsFinished() {
	if (zeroAtBottom) {
		return toteLifterino->getBotInput();
	} else {
		return toteLifterino->getTopInput();
	}
}

// Called once after isFinished returns true
void ZeroElevator::End() {
	toteLifterino->getEncoder()->Reset();
	toteLifterino->setZeroed(true);
	toteLifterino->setMotorSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ZeroElevator::Interrupted() {

}
