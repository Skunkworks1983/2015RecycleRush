#include <Commands/ToteLifting/zeroing/ZeroElevatorMagnet.h>

ZeroElevatorMag::ZeroElevatorMag() {
	Requires(toteLifter);
	triggered = false;
	zeroed = false;
}

// Called just before this Command runs the first time
void ZeroElevatorMag::Initialize() {
	toteLifter->setMotorSpeed(TOTE_LIFTER_ZERO_SPEED_MAG);
}

// Called repeatedly when this Command is scheduled to run
void ZeroElevatorMag::Execute() {
	//not tested, needs to be tested
	if (!triggered) {
		if (toteLifter->getElevatorInput()) {
			triggered = true;
			toteLifter->getEncoder()->Reset();
			toteLifter->setMotorSpeed(-TOTE_LIFTER_ZERO_SPEED_MAG);
		}
	}

	if (triggered) {
		if (toteLifter->getPosition() == -TOTE_LIFTER_MAG_SENSOR_POSITION) {
			toteLifter->getEncoder()->Reset();
			toteLifter->setMotorSpeed(0);
			zeroed = true;
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ZeroElevatorMag::IsFinished() {
	return zeroed;
}

// Called once after isFinished returns true
void ZeroElevatorMag::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ZeroElevatorMag::Interrupted() {

}
