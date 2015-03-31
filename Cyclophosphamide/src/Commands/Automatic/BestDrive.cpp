#include <Commands/Automatic/BestDrive.h>
#define AUTO_DRIVE_THRESHHOLD 0.0

BestDrive::BestDrive(float distance, Direction direction) {
	Requires(driveBase);
	this->direction = direction;
	targetDistance = distance * DRIVE_BASE_TICKS_PER_INCH;
}

// Called just before this Command runs the first time
void BestDrive::Initialize() {
	//driveBae->startRotPID();
	driveBase->zeroEncoders();
	driveBase->setModeAll(CANSpeedController::kPosition);
	driveBase->enablePIDAll(true);
	driveBase->setPIDAll(DRIVE_DRIVE_P, DRIVE_DRIVE_I, DRIVE_DRIVE_D);
	switch (direction) {
	case forward:
		driveBase->setAll(targetDistance);
		driveBase->getMotor(DriveBase::MotorSide::BACK_RIGHT)->Set(
				-targetDistance);
		break;
	case backward:
		driveBase->setAll(-targetDistance);
		break;
	case right:
		driveBase->getMotor(DriveBase::MotorSide::BACK_LEFT)->Set(targetDistance);
		driveBase->getMotor(DriveBase::MotorSide::BACK_RIGHT)->Set(
				targetDistance);
		driveBase->getMotor(DriveBase::MotorSide::FRONT_LEFT)->Set(
				-targetDistance);
		driveBase->getMotor(DriveBase::MotorSide::FRONT_RIGHT)->Set(
				-targetDistance);
		break;
	case left:
		driveBase->getMotor(DriveBase::MotorSide::BACK_LEFT)->Set(
				-targetDistance);
		driveBase->getMotor(DriveBase::MotorSide::BACK_RIGHT)->Set(
				-targetDistance);
		driveBase->getMotor(DriveBase::MotorSide::FRONT_LEFT)->Set(
				targetDistance);
		driveBase->getMotor(DriveBase::MotorSide::FRONT_RIGHT)->Set(
				targetDistance);
		break;
	}

}

// Called repeatedly when this Command is scheduled to run
void BestDrive::Execute() {
	SmartDashboard::PutNumber("Front left PID error",
			driveBase->getMotor(DriveBase::MotorSide::FRONT_RIGHT)->Get()
					- driveBase->getMotor(DriveBase::MotorSide::FRONT_RIGHT)->GetSetpoint());
}

// Make this return true when this Command no longer needs to run execute()
bool BestDrive::IsFinished() {
	return driveBase->getMotor(DriveBase::MotorSide::FRONT_LEFT)->GetEncPosition()
			> targetDistance - 30
			&& driveBase->getMotor(DriveBase::MotorSide::FRONT_LEFT)->GetEncPosition()
					< targetDistance + 30;
	//return driveBae->withinThreshhold(AUTO_DRIVE_THRESHHOLD, targetDistance);
}

// Called once after isFinished returns true
void BestDrive::End() {
	driveBase->zeroEncoders();
	driveBase->setAll(0);
	driveBase->enablePIDAll(false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BestDrive::Interrupted() {
	End();
}
