/*
 * LiftToHeightVelocity.cpp
 *
 *  Created on: Feb 11, 2015
 *      Author: S-4020395
 */

#include <Commands/ToteLifting/LiftToHeightVelocity.h>

LiftToHeightVelocity::LiftToHeightVelocity(double speed) :
		CommandBase("LiftToHeightVelocity") {
	Requires(toteLifter);
	this->speed = speed;
}

LiftToHeightVelocity::~LiftToHeightVelocity() {
}

void LiftToHeightVelocity::Initialize() {
	toteLifter->setMotorSpeed(speed);
}

void LiftToHeightVelocity::Execute() {
}

bool LiftToHeightVelocity::IsFinished() {
//split up for understanding
	return false;
	/*return (speed < 0 && toteLifterino->getBotInput())
	 || (speed > 0 && toteLifterino->getTopInput());*/
}

void LiftToHeightVelocity::End() {
	toteLifter->setMotorSpeed(0);
}

void LiftToHeightVelocity::Interrupted() {
	toteLifter->setMotorSpeed(0);
}
