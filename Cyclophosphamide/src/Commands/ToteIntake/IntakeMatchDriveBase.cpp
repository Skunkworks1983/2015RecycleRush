/*
 * IntakeMatchDriveBase.cpp
 *
 *  Created on: Mar 3, 2015
 *      Author: S-4020395
 */

#include <Commands/ToteIntake/IntakeMatchDriveBase.h>

IntakeMatchDriveBase::IntakeMatchDriveBase() :
		CommandBase("IntakeMatchDriveBase") {
	Requires(newToteIntakerino);
}

IntakeMatchDriveBase::~IntakeMatchDriveBase() {
	// TODO Auto-generated destructor stub
}

void IntakeMatchDriveBase::Initialize() {

}

void IntakeMatchDriveBase::Execute() {
	newToteIntakerino->setMotors(-(CommandBase::driveBae->getForward() * INTAKE_MATCH_DRIVE_CONSTANT));
}

bool IntakeMatchDriveBase::IsFinished() {
	return false;
}

void IntakeMatchDriveBase::End() {
	newToteIntakerino->setMotors(0);
}

void IntakeMatchDriveBase::Interrupted() {
	End();
}
