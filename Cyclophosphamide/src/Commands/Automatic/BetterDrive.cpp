#include "BetterDrive.h"
#define DRIVE_TICKS_TO_DISTANCE 420.0
#define AUTO_DRIVE_THRESHHOLD 1337.0
BetterDrive::BetterDrive(float distance)
{
	Requires(driveBase);

	targetDistance = distance/DRIVE_TICKS_TO_DISTANCE;
	distanceRemain = targetDistance;
	initialPos = 0;
}

// Called just before this Command runs the first time
void BetterDrive::Initialize()
{
	float currentPos = driveBase->getSpecialMotor()->GetEncPosition();
	driveBase->getSpecialMotor()->EnableControl();
	driveBase->getSpecialMotor()->SetPID(DRIVE_DRIVE_P,DRIVE_DRIVE_I,DRIVE_DRIVE_D);
	driveBase->getSpecialMotor()->Set(targetDistance+currentPos);
	initialPos = currentPos;

}

// Called repeatedly when this Command is scheduled to run
void BetterDrive::Execute()
{
 // ayy lma0
}

// Make this return true when this Command no longer needs to run execute()
bool BetterDrive::IsFinished()
{
	float currentPos = driveBase->getSpecialMotor()->GetEncPosition();
	distanceRemain = currentPos-initialPos;
	return distanceRemain < AUTO_DRIVE_THRESHHOLD;
}

// Called once after isFinished returns true
void BetterDrive::End()
{
	driveBase->getSpecialMotor()->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BetterDrive::Interrupted()
{
	End();
}
