#include <Commands/ToteIntake/NewToteIntake.h>
#include <Subsystems/NewToteIntakerino.h>

NewToteIntake::NewToteIntake(Direction direction, double timeout) {
	Requires(newToteIntakerino);
	this->direction = direction;
	SetTimeout(timeout);
}

// Called just before this Command runs the first time
void NewToteIntake::Initialize() {
	switch (direction) {
	case forward:
		newToteIntakerino->setMotors(TOTE_INTAKE_MOTOR_FULL);
		break;
	case reverse:
		newToteIntakerino->setMotors(-TOTE_INTAKE_MOTOR_FULL);
		break;
	case stopped:
		newToteIntakerino->setMotors(0);
		break;
	}
}

// Called repeatedly when this Command is scheduled to run
// Make this return true when this Command no longer needs to run execute()
void NewToteIntake::Execute() {
	//toteIntakerino->runIfTote();
}

// Make this return true when this Command no longer needs to run execute()
bool NewToteIntake::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void NewToteIntake::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void NewToteIntake::Interrupted() {

}
