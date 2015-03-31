#include <Commands/ToteIntake/RunToteIntake.h>

RunToteIntake::RunToteIntake(float speed) {
	Requires(toteIntake);
	this->speed = speed;
}

// Called just before this Command runs the first time
void RunToteIntake::Initialize() {
	toteIntake->setMotor(speed);
}

// Called repeatedly when this Command is scheduled to run
// Make this return true when this Command no longer needs to run execute()
void RunToteIntake::Execute() {
	//toteIntakerino->runIfTote();
}

// Make this return true when this Command no longer needs to run execute()
bool RunToteIntake::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void RunToteIntake::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunToteIntake::Interrupted() {

}
