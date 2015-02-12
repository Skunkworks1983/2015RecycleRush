#include "LiftToHeight.h"

LiftToHeight::LiftToHeight(double destination) :
		CommandBase("LiftToHeight") {
	Requires(toteLifterino);
	this->destination = destination;
}

// Called just before this Command runs the first time
void LiftToHeight::Initialize() {
	toteLifterino->setSetPoints(destination);
	toteLifterino->enablePID(true);
}

// Called repeatedly when this Command is scheduled to run
void LiftToHeight::Execute() {
	//Nothing?
	if (count++ > 25) {
		if (toteLifterino->getLeftMotor()->GetP()
				!= SmartDashboard::GetNumber("P")) {
			toteLifterino->getLeftMotor()->SetP(SmartDashboard::GetNumber("P"));
		}
		if (toteLifterino->getLeftMotor()->GetI()
				!= SmartDashboard::GetNumber("I")) {
			toteLifterino->getLeftMotor()->SetI(SmartDashboard::GetNumber("I"));
		}
		if (toteLifterino->getLeftMotor()->GetI()
				!= SmartDashboard::GetNumber("I")) {
			toteLifterino->getLeftMotor()->SetI(SmartDashboard::GetNumber("I"));
		}
	}

	SmartDashboard::PutNumber("Encoder Value:",
			toteLifterino->getLeftMotor()->GetEncPosition());
	SmartDashboard::PutNumber("MotorSetPoint",
			toteLifterino->getLeftMotor()->GetSetpoint());
	SmartDashboard::PutNumber("MotorSpeed",
			toteLifterino->getLeftMotor()->GetSpeed());
	SmartDashboard::PutNumber("Destination", destination);

	if (oi->isJoystickButtonPressed(true, 1)) {
		destination = TOTE_LIFTER_FLOOR;
	} else if (oi->isJoystickButtonPressed(true, 2)) {
		destination = TOTE_LIFTER_LOW;
	} else if (oi->isJoystickButtonPressed(true, 3)) {
		destination = TOTE_LIFTER_MID;
	} else if (oi->isJoystickButtonPressed(true, 4)) {
		destination = TOTE_LIFTER_HIGH;
	}

	if (destination != oldDest) {
		toteLifterino->setSetPoints(destination);
		oldDest = destination;
	}
	//failsafe could not work
//	if (toteLifterino->getElevatorDigitalInput() && destination < 0) {
//		toteLifterino->getLeftMotor()->SetPosition(0);
//		End();
//	}
}

// Make this return true when this Command no longer needs to run execute()
bool LiftToHeight::IsFinished() {
	//don't end when at destination becuase it needs to hold the totes up until there is a tote under
	return false;
	//if (destination != TOTE_LIFTER_FLOOR) {
	//	return toteLifterino->isToteUnder();
	/* else {
	 return toteLifterino->getLeftMotor()->GetEncPosition()
	 + TOTE_LIFTER_ENCODER_DEADBAND < TOTE_LIFTER_FLOOR
	 || toteLifterino->getLeftMotor()->GetEncPosition()
	 - TOTE_LIFTER_ENCODER_DEADBAND > TOTE_LIFTER_FLOOR;
	 }*/
}

// Called once after isFinished returns true
void LiftToHeight::End() {
	toteLifterino->enablePID(false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftToHeight::Interrupted() {
	End();
}
