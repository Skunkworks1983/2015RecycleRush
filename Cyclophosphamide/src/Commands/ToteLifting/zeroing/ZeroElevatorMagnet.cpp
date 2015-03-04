#include <Commands/ToteLifting/zeroing/ZeroElevatorMagnet.h>

ZeroElevatorMag::ZeroElevatorMag() {
	Requires(toteLifterino);
	triggered = false;
	zeroed = false;
}

// Called just before this Command runs the first time
void ZeroElevatorMag::Initialize() {
	toteLifterino->setMotorSpeed(TOTE_LIFTER_ZERO_SPEED_MAG);
}

// Called repeatedly when this Command is scheduled to run
void ZeroElevatorMag::Execute() {
	//not tested, needs to be tested
	if (!triggered) {
		if (toteLifterino->getMagInput()) {
			triggered = true;
			toteLifterino->getEncoder()->Reset();
			toteLifterino->setMotorSpeed(-TOTE_LIFTER_ZERO_SPEED_MAG);
		}
	}

	if (triggered) {
		if (toteLifterino->getPosition() == -TOTE_LIFTER_MAG_SENSOR_POSITION) {
			toteLifterino->getEncoder()->Reset();
			toteLifterino->setMotorSpeed(0);
			toteLifterino->setZeroed(true);
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
