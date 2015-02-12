#include <Commands/Automatic/BestDrive.h>
#define AUTO_DRIVE_THRESHHOLD 0.0

BestDrive::BestDrive(float distance, Direction direction) {
	Requires(driveBase);
	this->direction = direction;
	targetDistance = distance;
}

// Called just before this Command runs the first time
void BestDrive::Initialize() {
	driveBase->startRotPID();
	driveBase->zeroEncoders();
	driveBase->setModeAll(CANSpeedController::kPosition);
	driveBase->enablePIDAll(true);
	driveBase->setPIDAll(DRIVE_DRIVE_P, DRIVE_DRIVE_I, DRIVE_DRIVE_D);
	switch(direction){
	case forward:
		driveBase->setAll(targetDistance);
		break;
	case backward:
		driveBase->setAll(-targetDistance);
		break;
	case right:
		driveBase->getMotor(DriveBae::MotorSide::BACK_LEFT)->Set(targetDistance);
		driveBase->getMotor(DriveBae::MotorSide::BACK_RIGHT)->Set(targetDistance);
		driveBase->getMotor(DriveBae::MotorSide::FRONT_LEFT)->Set(-targetDistance);
		driveBase->getMotor(DriveBae::MotorSide::FRONT_RIGHT)->Set(-targetDistance);
		break;
	case left:
		driveBase->getMotor(DriveBae::MotorSide::BACK_LEFT)->Set(-targetDistance);
		driveBase->getMotor(DriveBae::MotorSide::BACK_RIGHT)->Set(-targetDistance);
		driveBase->getMotor(DriveBae::MotorSide::FRONT_LEFT)->Set(targetDistance);
		driveBase->getMotor(DriveBae::MotorSide::FRONT_RIGHT)->Set(targetDistance);
		break;
	}
	SmartDashboard::PutNumber("Initial enc value", driveBase->getMotor(DriveBae::FRONT_LEFT)->GetEncPosition());
}

// Called repeatedly when this Command is scheduled to run
void BestDrive::Execute() {
	// ayy lma0
	SmartDashboard::PutNumber("Current enc value", driveBase->getMotor(DriveBae::FRONT_LEFT)->GetEncPosition());
	SmartDashboard::PutNumber("Drive PID setpoint", driveBase->getMotor(DriveBae::FRONT_LEFT)->GetSetpoint());
}

// Make this return true when this Command no longer needs to run execute()
bool BestDrive::IsFinished() {
	return driveBase->withinThreshhold(AUTO_DRIVE_THRESHHOLD, targetDistance);
}

// Called once after isFinished returns true
void BestDrive::End() {
	driveBase->setAll(0);
	driveBase->enablePIDAll(false);
	SmartDashboard::PutNumber("Final enc value", driveBase->getMotor(DriveBae::FRONT_LEFT)->GetEncPosition());
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BestDrive::Interrupted() {
	End();
}
