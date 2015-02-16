/*
 * LiftToHeightVelocity.cpp
 *
 *  Created on: Feb 11, 2015
 *      Author: S-4020395
 */

#include <Commands/ToteHandling/LiftToHeightVelocity.h>

LiftToHeightVelocity::LiftToHeightVelocity(double speed) :
		CommandBase("LiftToHeightVelocity") {
	Requires(toteLifterino);
	this->speed = speed;
	toteLifterino->enablePID(false);
}

LiftToHeightVelocity::~LiftToHeightVelocity() {
}

void LiftToHeightVelocity::Initialize() {
	if ((speed < 0
			&& toteLifterino->getEncoder()->GetDistance()
					<= 0 + TOTE_LIFTER_END_TOLERANCE)
			|| (speed > 0
					&& toteLifterino->getEncoder()->GetDistance()
							>= TOTE_LIFTER_MAX_DISTANCE)) {
		//return true;
		return;
	} else {
		toteLifterino->setMotorSpeed(speed);
	}
}

void LiftToHeightVelocity::Execute() {
}

bool LiftToHeightVelocity::IsFinished() {
//split up for understanding
	if (speed
			> 0&& toteLifterino->getEncoder()->GetDistance() >= TOTE_LIFTER_MAX_DISTANCE - TOTE_LIFTER_END_TOLERANCE) {
		return true;
	}
	if (speed
			< 0&& toteLifterino->getEncoder()->GetDistance() <= 0 + TOTE_LIFTER_END_TOLERANCE) {
		return true;
	}
	return false;
}

void LiftToHeightVelocity::End() {
	toteLifterino->setMotorSpeed(0);
}

void LiftToHeightVelocity::Interrupted() {
	toteLifterino->setMotorSpeed(0);
}
