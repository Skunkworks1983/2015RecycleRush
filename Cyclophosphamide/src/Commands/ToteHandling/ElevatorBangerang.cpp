#include "ElevatorBangerang.h"

ElevatorBangerang::ElevatorBangerang(double destination) :
		CommandBase("LiftToHeight") {
	Requires(toteLifterino);
	this->destination = destination;
//	if ((1 / (destination - toteLifterino->getRightMotor())) * destination
//			- toteLifterino->getRightMotor() == 1) {
//
//	} else {
//
//	}
}

// Called just before this Command runs the first time
void ElevatorBangerang::Initialize() {
	reachedPosition = false;
}

// Called repeatedly when this Command is scheduled to run
void ElevatorBangerang::Execute() {
	if (!reachedPosition) {
		if (toteLifterino->closeEnough(destination)) {
			reachedPosition = true;
		} else {
//			toteLifterino->setMotorSpeed()
		}
	} else {
		if (!toteLifterino->closeEnough(destination)) {

		} else {

		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorBangerang::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ElevatorBangerang::End() {
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorBangerang::Interrupted() {
	//toteLifterino->setSetPoints(toteLifterino->getEncoder()->GetDistance());
}
