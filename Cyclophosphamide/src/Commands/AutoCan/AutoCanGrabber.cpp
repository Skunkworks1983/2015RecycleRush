/*
 * PushAutoCanArms.cpp
 *
 *  Created on: Feb 14, 2015
 *      Author: Administrator
 */

#include "AutoCanGrabber.h"

AutoCanGrabber::AutoCanGrabber(bool down) {
	// TODO Auto-generated constructor stub
	if (down) {
			setpoint = DoubleSolenoid::kForward;
		} else {
			setpoint = DoubleSolenoid::kReverse;
		}
		Requires(canCollecterino);
}

AutoCanGrabber::~AutoCanGrabber() {
	// TODO Auto-generated destructor stub
}

void AutoCanGrabber::Initialize() {

}

void AutoCanGrabber::Execute() {

}

bool AutoCanGrabber::IsFinished() {
	return true;
}

void AutoCanGrabber::End() {

}

void AutoCanGrabber::Interrupted() {
}
