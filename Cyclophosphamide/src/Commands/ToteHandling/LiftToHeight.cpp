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
		if (toteLifterino->getPID()->GetP() != SmartDashboard::GetNumber("P")) {
			toteLifterino->getPID()->SetPID(SmartDashboard::GetNumber("P"),
					toteLifterino->getPID()->GetI(),
					toteLifterino->getPID()->GetD());
		}
		if (toteLifterino->getPID()->GetI() != SmartDashboard::GetNumber("I")) {
			toteLifterino->getPID()->SetPID(toteLifterino->getPID()->GetP(),
					SmartDashboard::GetNumber("I"),
					toteLifterino->getPID()->GetD());
		}
		if (toteLifterino->getPID()->GetD() != SmartDashboard::GetNumber("D")) {
			toteLifterino->getPID()->SetPID(toteLifterino->getPID()->GetP(),
					toteLifterino->getPID()->GetI(),
					SmartDashboard::GetNumber("D"));
		}
	}

	SmartDashboard::PutNumber("Encoder Value:",
			toteLifterino->getEncoder()->Get());
	SmartDashboard::PutNumber("MotorSetPoint",
			toteLifterino->getPID()->GetSetpoint());
	SmartDashboard::PutNumber("MotorSpeed",
			toteLifterino->getEncoder()->GetRate());
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
}

// Make this return true when this Command no longer needs to run execute()
bool LiftToHeight::IsFinished() {
	//don't end when at destination because PID needs to hold the totes up until there is a tote underneath
	return false;
	// return toteLifterino->getElevatorDigitalInput() && destination < 0
	// return toteLifterino->isToteUnder();
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
