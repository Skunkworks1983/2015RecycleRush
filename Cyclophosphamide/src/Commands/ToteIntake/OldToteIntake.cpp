#include <Commands/ToteIntake/OldToteIntake.h>

OldToteIntake::OldToteIntake(Direction direction) {
	Requires(oldToteIntakerino);
	this->direction = direction;
}

// Called just before this Command runs the first time
void OldToteIntake::Initialize() {
	switch (direction) {
	case forward:
		oldToteIntakerino->setMotor(TOTE_INTAKE_MOTOR_FULL);
		break;
	case reverse:
		oldToteIntakerino->setMotor(-TOTE_INTAKE_MOTOR_FULL);
		break;
	case stopped:
		oldToteIntakerino->hold();
		break;
	}
}

// Called repeatedly when this Command is scheduled to run
// Make this return true when this Command no longer needs to run execute()
void OldToteIntake::Execute() {
	//toteIntakerino->runIfTote();
}

// Make this return true when this Command no longer needs to run execute()
bool OldToteIntake::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void OldToteIntake::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void OldToteIntake::Interrupted() {

}
