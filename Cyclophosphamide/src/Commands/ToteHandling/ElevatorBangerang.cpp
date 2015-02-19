#include "ElevatorBangerang.h"

ElevatorBangerang::ElevatorBangerang(double destination) :
		CommandBase("LiftToHeight") {
	Requires(toteLifterino);
	this->destination = destination;
}

// Called just before this Command runs the first time
void ElevatorBangerang::Initialize() {
	if (destination == TOTE_LIFTER_FLOOR_HEIGHT) {
		toteLifterino->setMotorSpeed(TOTE_LIFTER_DOWN_SPEED);
	}else{
		toteLifterino->enablePID(true);
		toteLifterino->setSetPoints(destination);
	}
}

// Called repeatedly when this Command is scheduled to run
void ElevatorBangerang::Execute() {

	/*
	if (destination == TOTE_LIFTER_FLOOR_HEIGHT
			&& toteLifterino->getEncoder()->Get()
					== oldEncoderValue&& toteLifterino->getEncoder()->Get() < TOTE_LIFTER_ENCODER_CLOSE_TO_ZERO) {
		count++;
	}
	if (count > TOTE_LIFTER_COUNT_ZEROED) {
		toteLifterino->getEncoder()->Reset();
	}
	*/
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
