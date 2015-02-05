#include <Commands/ToteHandling/LiftToHeight.h>

LiftToHeight::LiftToHeight(double destination) {
	Requires(toteLifterino);
	this->destination = destination;
	motorSpeed = 1;
}

// Called just before this Command runs the first time
void LiftToHeight::Initialize() {
#if TOTE_LIFTER_USING_PID
	toteLifterino->enablePID(true);
	toteLifterino->setSetPoints(destination);
#else
	startingPos = toteLifterino->getEncoder()->GetDistance();
	oldDiff = toteLifterino->getEncoder()->GetDistance() - destination;
#endif
}

// Called repeatedly when this Command is scheduled to run
void LiftToHeight::Execute() {
#if TOTE_LIFTER_USING_PID
	//Nothing?
#else
	double diff = toteLifterino->getEncoder()->GetDistance() - destination;
	motorSpeed += LIFT_TO_HEIGHT_CONSTANT * (diff - oldDiff);
	if (motorSpeed > 1) {
		motorSpeed = 1;
	}
	if (motorSpeed < -1) {
		motorSpeed = -1;
	}
	toteLifterino->setMotors(motorSpeed);

	oldDiff = diff;
#endif
}

// Make this return true when this Command no longer needs to run execute()
bool LiftToHeight::IsFinished() {
	//don't end when at destination becuase it needs to hold the totes up until there is a tote under
	return toteLifterino->isToteUnder();
}

// Called once after isFinished returns true
void LiftToHeight::End() {
	toteLifterino->setMotors(0);
#if TOTE_LIFTER_USING_PID
	toteLifterino->enablePID(false);
#endif
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftToHeight::Interrupted() {
	toteLifterino->setMotors(0);
#if TOTE_LIFTER_USING_PID
	toteLifterino->enablePID(false);
#endif
}
