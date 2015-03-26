#include <Commands/Automatic/BestDrive.h>
#define AUTO_DRIVE_THRESHHOLD 0.0

BestDrive::BestDrive(float distance, Direction direction) {
	Requires(driveBae);
	this->direction = direction;
	targetDistance = distance * DRIVE_BASE_TICKS_PER_INCH;
}

// Called just before this Command runs the first time
void BestDrive::Initialize() {
	//driveBae->startRotPID();
	driveBae->zeroEncoders();
	driveBae->setModeAll(CANSpeedController::kPosition);
	driveBae->enablePIDAll(true);
	driveBae->setPIDAll(DRIVE_DRIVE_P, DRIVE_DRIVE_I, DRIVE_DRIVE_D);
	switch (direction) {
	case forward:
		driveBae->setAll(targetDistance);
		driveBae->getMotor(DriveBae::MotorSide::BACK_RIGHT)->Set(
				-targetDistance);
		break;
	case backward:
		driveBae->setAll(-targetDistance);
		break;
	case right:
		driveBae->getMotor(DriveBae::MotorSide::BACK_LEFT)->Set(targetDistance);
		driveBae->getMotor(DriveBae::MotorSide::BACK_RIGHT)->Set(
				targetDistance);
		driveBae->getMotor(DriveBae::MotorSide::FRONT_LEFT)->Set(
				-targetDistance);
		driveBae->getMotor(DriveBae::MotorSide::FRONT_RIGHT)->Set(
				-targetDistance);
		break;
	case left:
		driveBae->getMotor(DriveBae::MotorSide::BACK_LEFT)->Set(
				-targetDistance);
		driveBae->getMotor(DriveBae::MotorSide::BACK_RIGHT)->Set(
				-targetDistance);
		driveBae->getMotor(DriveBae::MotorSide::FRONT_LEFT)->Set(
				targetDistance);
		driveBae->getMotor(DriveBae::MotorSide::FRONT_RIGHT)->Set(
				targetDistance);
		break;
	}

}

// Called repeatedly when this Command is scheduled to run
void BestDrive::Execute() {
	SmartDashboard::PutNumber("Front left PID error",
			driveBae->getMotor(DriveBae::MotorSide::FRONT_RIGHT)->Get()
					- driveBae->getMotor(DriveBae::MotorSide::FRONT_RIGHT)->GetSetpoint());
}

// Make this return true when this Command no longer needs to run execute()
bool BestDrive::IsFinished() {
	return driveBae->getMotor(DriveBae::MotorSide::FRONT_LEFT)->GetEncPosition()
			> targetDistance - 30
			&& driveBae->getMotor(DriveBae::MotorSide::FRONT_LEFT)->GetEncPosition()
					< targetDistance + 30;
	//return driveBae->withinThreshhold(AUTO_DRIVE_THRESHHOLD, targetDistance);
}

// Called once after isFinished returns true
void BestDrive::End() {
	driveBae->zeroEncoders();
	driveBae->setAll(0);
	driveBae->enablePIDAll(false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BestDrive::Interrupted() {
	End();
}
