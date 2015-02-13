/*
 * LiftToHeightVelocity.cpp
 *
 *  Created on: Feb 11, 2015
 *      Author: S-4020395
 */

#include <Commands/ToteHandling/LiftToHeightVelocity.h>

LiftToHeightVelocity::LiftToHeightVelocity() :
		CommandBase("LiftToHeightVelocity") {
	Requires(toteLifterino);
}

LiftToHeightVelocity::~LiftToHeightVelocity() {

}

void LiftToHeightVelocity::Initialize() {
	toteLifterino->enablePID(false);
}
void LiftToHeightVelocity::Execute() {
	double aMax = OI_LINEARPOT_MAX;
	double val = oi->getAnalogValue(OI_LINEARPOT_TOTE_LIFTER_OVR_PORT);
	toteLifterino->setMotorSpeed(val / aMax);
}
bool LiftToHeightVelocity::IsFinished() {
	return false;
}
void LiftToHeightVelocity::End() {

}
void LiftToHeightVelocity::Interrupted() {

}
