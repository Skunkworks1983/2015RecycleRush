#include "LiftToHeight.h"

LiftToHeight::LiftToHeight(double destination) :
		CommandBase("LiftToHeight") {
	Requires(toteLifterino);
	this->destination = destination;
	motorSpeed = 1;
}

// Called just before this Command runs the first time
void LiftToHeight::Initialize() {
#if TOTE_LIFTER_USING_PID
	toteLifterino->enablePID(true);
	//toteLifterino->setSetPoints(destination);
#else
	startingPos = toteLifterino->getEncoder()->GetDistance();
	oldDiff = toteLifterino->getEncoder()->GetDistance() - destination;
#endif
}

// Called repeatedly when this Command is scheduled to run
void LiftToHeight::Execute() {
#if TOTE_LIFTER_USING_PID
	//Nothing?
	SmartDashboard::PutNumber("Encoder Value:",
			toteLifterino->getLeftMotor()->GetEncPosition());
	//failsafe could not work
	if (toteLifterino->getElevatorDigitalInput() && destination < 0) {
		toteLifterino->getLeftMotor()->SetPosition(0);
		End();
	}
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
	if (destination != TOTE_LIFTER_FLOOR) {
		return toteLifterino->isToteUnder();
	} else {
		return toteLifterino->getLeftMotor()->GetEncPosition()
				+ TOTE_LIFTER_ENCODER_DEADBAND < TOTE_LIFTER_FLOOR
				|| toteLifterino->getLeftMotor()->GetEncPosition()
						- TOTE_LIFTER_ENCODER_DEADBAND > TOTE_LIFTER_FLOOR;
	}
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
	End();
}
