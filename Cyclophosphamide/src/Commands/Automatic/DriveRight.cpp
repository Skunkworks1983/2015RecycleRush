#include "DriveRight.h"
#define AUTO_DRIVE_THRESHHOLD 0.0

DriveRight::DriveRight(double distance)
{
	Requires(driveBase);
	this->distance = distance;
}

// Called just before this Command runs the first time
void DriveRight::Initialize()
{
	driveBase->startRotPID();
	driveBase->zeroEncoders();
	driveBase->setModeAll(CANSpeedController::kPosition);
	driveBase->enablePIDAll(true);
	driveBase->setPIDAll(DRIVE_DRIVE_P, DRIVE_DRIVE_I, DRIVE_DRIVE_D);

	//Distance could be different for right versus forward
	driveBase->getMotor(DriveBae::MotorSide::BACK_LEFT)->Set(distance);
	driveBase->getMotor(DriveBae::MotorSide::BACK_RIGHT)->Set(-distance);
	driveBase->getMotor(DriveBae::MotorSide::FRONT_LEFT)->Set(-distance);
	driveBase->getMotor(DriveBae::MotorSide::FRONT_RIGHT)->Set(distance);
}

// Called repeatedly when this Command is scheduled to run
void DriveRight::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool DriveRight::IsFinished()
{
	return driveBase->withinThreshhold(AUTO_DRIVE_THRESHHOLD, distance);
}

// Called once after isFinished returns true
void DriveRight::End()
{
	driveBase->setAll(0);
	driveBase->enablePIDAll(false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveRight::Interrupted()
{
	End();
}
