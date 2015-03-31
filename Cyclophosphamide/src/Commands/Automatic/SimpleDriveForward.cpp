#include <CANSpeedController.h>
#include <CANTalon.h>
#include <Commands/Automatic/SimpleDriveForward.h>
#include <RobotMap.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Subsystems/DriveBase.h>
#include <string>

#define AUTO_DRIVE_THRESHOLD 30
#define FABS(a) a < 0 ? -1*a : a

SimpleDriveForward::SimpleDriveForward(float targetInch, double speed) {
	Requires(driveBase);
	this->speed = speed;
	driveBase->zeroEncoders();
	this->targetTicks = (targetInch * DRIVE_BASE_TICKS_PER_INCH);
	SmartDashboard::PutString("DriveForwardStatus", "Constructor!");
	driveBase->setModeAll(CANSpeedController::kPercentVbus);
	driveBase->enablePIDAll(false);
}

SimpleDriveForward::SimpleDriveForward(float targetInch, double speed,
		double timeout) {
	SetTimeout(timeout);
	this->timeout = timeout;
	this->speed = speed;
	driveBase->zeroEncoders();
	this->targetTicks = (targetInch * DRIVE_BASE_TICKS_PER_INCH);
	SmartDashboard::PutString("DriveForwardStatus", "Constructor!");
	driveBase->setModeAll(CANSpeedController::kPercentVbus);
	driveBase->enablePIDAll(false);
}

// Called just before this Command runs the first time
void SimpleDriveForward::Initialize() {
	driveBase->zeroEncoders();
	startingPos =
			driveBase->getMotor(DriveBase::MotorSide::FRONT_LEFT)->GetEncPosition();
	SmartDashboard::PutNumber("start", startingPos);
	signedSpeed = targetTicks < 0 ? speed : -speed;
	driveBase->setAll(signedSpeed);
	///driveBae->setSpeed(speed, speed, speed, speed);
	SmartDashboard::PutString("DriveForwardStatus", "Initialize!");
}

// Called repeatedly when this Command is scheduled to run
void SimpleDriveForward::Execute() {
	driveBase->setAll(signedSpeed);
	SmartDashboard::PutNumber("newDriveEnc",
			driveBase->getMotor(DriveBase::MotorSide::FRONT_LEFT)->GetEncPosition());
	double pos =
			driveBase->getMotor(DriveBase::MotorSide::FRONT_LEFT)->GetEncPosition()
					- startingPos;

	if (pos < 0) {
		pos *= -1;	//wtf fabs doesn't work...
	}

	if (targetTicks < 0) {
		targetTicks *= -1;
	}

	double diff = targetTicks - pos;
	SmartDashboard::PutNumber("SimpleDriveForwardDiff", diff);
	SmartDashboard::PutString("DriveForwardStatus", "Execute!");

}

// Make this return true when this Command no longer needs to run execute()
bool SimpleDriveForward::IsFinished() {
	SmartDashboard::PutNumber("Target", targetTicks);
	SmartDashboard::PutNumber("DriveEnc",
			driveBase->getMotor(DriveBase::MotorSide::FRONT_LEFT)->GetEncPosition());

	double pos =
			driveBase->getMotor(DriveBase::MotorSide::FRONT_LEFT)->GetEncPosition()
					- startingPos;

	if (pos < 0) {
		pos *= -1.0;	//wtf fabs doesn't work...
	}

	if (targetTicks < 0) {
		targetTicks *= -1.0;
	}

	double diff = targetTicks - pos;

	SmartDashboard::PutNumber("ughAuto", diff);
	SmartDashboard::PutBoolean("timeoutya", (timeout > 0 && IsTimedOut()));
	return diff < 200 || (timeout > 0 && IsTimedOut());
	//return driveBae->withinThreshhold(AUTO_DRIVE_THRESHOLD, targetTicks);
}

// Called once after isFinished returns true
void SimpleDriveForward::End() {
	SmartDashboard::PutString("DriveForwardStatus", "End!");
	driveBase->setSpeed(0, 0, 0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SimpleDriveForward::Interrupted() {
	SmartDashboard::PutString("DriveForwardStatus",
			SmartDashboard::GetString("DriveForwardStatus")
					+ " then Interupted!");
	End();
}
