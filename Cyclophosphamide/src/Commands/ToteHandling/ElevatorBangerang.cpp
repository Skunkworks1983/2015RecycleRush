#include "ElevatorBangerang.h"

ElevatorBangerang::ElevatorBangerang(double destination) :
		CommandBase("LiftToHeight") {
	Requires(toteLifterino);
	this->destination = destination;
}

// Called just before this Command runs the first time
void ElevatorBangerang::Initialize() {
	if (destination == TOTE_LIFTER_FLOOR_HEIGHT
			&& !toteLifterino->closeEnough(TOTE_LIFTER_FLOOR_HEIGHT)) {
		toteLifterino->setMotorSpeed(TOTE_LIFTER_DOWN_SPEED);
	} else {
		toteLifterino->enablePID(true);
		toteLifterino->setSetPoints(destination);
	}
}

// Called repeatedly when this Command is scheduled to run
void ElevatorBangerang::Execute() {
	if (destination != TOTE_LIFTER_FLOOR_HEIGHT) {
		if (!toteLifterino->getPID()->IsEnabled()
				&& !toteLifterino->lowerThan(destination)) {
			toteLifterino->setMotorSpeed(0);
			SmartDashboard::PutString("ElevatorBangBangStatus",
					"motorSpeed(0)");
		} else {
			if (toteLifterino->closeEnough(destination)) {
				toteLifterino->enablePID(false);
				SmartDashboard::PutString("ElevatorBangBangStatus",
						"disabledPID");
			} else {
				if (toteLifterino->lowerThan(
				TOTE_LIFTER_BANGBANG_TOLERANCE_1)) {
					if (!toteLifterino->lowerThan(
					TOTE_LIFTER_BANGBANG_TOLERANCE_2)) {
						/* Here, it is in between the tolerance for being too low to be on
						 *  target but not low enough to need the pid to be enabled  */
						toteLifterino->setMotorSpeed(
						TOTE_LIFTER_BANG_BANG_UP_SPEED);
						SmartDashboard::PutString("ElevatorBangBangStatus",
								"motorSpeed(.5)");
					} else {
						/*
						 * Here, it is too low for simply pulsing the motor speed,
						 * and needs the PID to send it back up to position
						 */
						toteLifterino->setMotorSpeed(0); //just in case
						toteLifterino->enablePID(true);
						toteLifterino->setSetPoints(destination);
						SmartDashboard::PutString("ElevatorBangBangStatus",
								"enablePID,setPoint");
					}
				}
			}
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorBangerang::IsFinished() {
	if (destination == TOTE_LIFTER_FLOOR_HEIGHT) {
		return toteLifterino->closeEnough(TOTE_LIFTER_FLOOR_HEIGHT);
	} else {
		return false;
	}
}

// Called once after isFinished returns true
void ElevatorBangerang::End() {
	toteLifterino->setMotorSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorBangerang::Interrupted() {
	toteLifterino->setMotorSpeed(0);
}
