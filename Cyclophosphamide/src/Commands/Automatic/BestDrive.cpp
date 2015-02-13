#include <Commands/Automatic/BestDrive.h>
#define AUTO_DRIVE_THRESHHOLD 0.0

BestDrive::BestDrive(float distance, Direction direction) {
	Requires(driveBae);
	this->direction = direction;
	targetDistance = distance;
}

// Called just before this Command runs the first time
void BestDrive::Initialize() {
	driveBae->startRotPID();
	driveBae->zeroEncoders();
	driveBae->setModeAll(CANSpeedController::kPosition);
	driveBae->enablePIDAll(true);
	driveBae->setPIDAll(DRIVE_DRIVE_P, DRIVE_DRIVE_I, DRIVE_DRIVE_D);
	switch(direction){
	case forward:
		driveBae->setAll(targetDistance);
		break;
	case backward:
		driveBae->setAll(-targetDistance);
		break;
	case right:
		driveBae->getMotor(DriveBae::MotorSide::BACK_LEFT)->Set(targetDistance);
		driveBae->getMotor(DriveBae::MotorSide::BACK_RIGHT)->Set(targetDistance);
		driveBae->getMotor(DriveBae::MotorSide::FRONT_LEFT)->Set(-targetDistance);
		driveBae->getMotor(DriveBae::MotorSide::FRONT_RIGHT)->Set(-targetDistance);
		break;
	case left:
		driveBae->getMotor(DriveBae::MotorSide::BACK_LEFT)->Set(-targetDistance);
		driveBae->getMotor(DriveBae::MotorSide::BACK_RIGHT)->Set(-targetDistance);
		driveBae->getMotor(DriveBae::MotorSide::FRONT_LEFT)->Set(targetDistance);
		driveBae->getMotor(DriveBae::MotorSide::FRONT_RIGHT)->Set(targetDistance);
		break;
	}
	SmartDashboard::PutNumber("Initial enc value", driveBae->getMotor(DriveBae::FRONT_LEFT)->GetEncPosition());
}

// Called repeatedly when this Command is scheduled to run
void BestDrive::Execute() {
	// ayy lma0
	SmartDashboard::PutNumber("Current enc value", driveBae->getMotor(DriveBae::FRONT_LEFT)->GetEncPosition());
	SmartDashboard::PutNumber("Drive PID setpoint", driveBae->getMotor(DriveBae::FRONT_LEFT)->GetSetpoint());
}

// Make this return true when this Command no longer needs to run execute()
bool BestDrive::IsFinished() {
	return driveBae->withinThreshhold(AUTO_DRIVE_THRESHHOLD, targetDistance);
}

// Called once after isFinished returns true
void BestDrive::End() {
	driveBae->setAll(0);
	driveBae->enablePIDAll(false);
	SmartDashboard::PutNumber("Final enc value", driveBae->getMotor(DriveBae::FRONT_LEFT)->GetEncPosition());
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BestDrive::Interrupted() {
	End();
}
