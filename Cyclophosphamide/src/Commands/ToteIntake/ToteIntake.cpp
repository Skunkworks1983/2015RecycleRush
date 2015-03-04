#include <Commands/ToteIntake/ToteIntake.h>
#include <Subsystems/ToteIntakerino.h>

ToteIntake::ToteIntake(Direction direction, double timeout) {
	Requires(toteIntakerino);
	this->direction = direction;
	SetTimeout(timeout);
}

// Called just before this Command runs the first time
void ToteIntake::Initialize() {
	switch (direction) {
	case forward:
		toteIntakerino->setMotors(TOTE_INTAKE_MOTOR_FULL);
		break;
	case reverse:
		toteIntakerino->setMotors(-TOTE_INTAKE_MOTOR_FULL);
		break;
	case stopped:
		toteIntakerino->setMotors(0);
		break;
	}
}

// Called repeatedly when this Command is scheduled to run
// Make this return true when this Command no longer needs to run execute()
void ToteIntake::Execute() {
	//toteIntakerino->runIfTote();
}

// Make this return true when this Command no longer needs to run execute()
bool ToteIntake::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void ToteIntake::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToteIntake::Interrupted() {

}
