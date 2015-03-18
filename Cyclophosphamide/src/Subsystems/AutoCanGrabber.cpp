/*
 * AutoCanGrabber.cpp
 *
 *  Created on: Mar 18, 2015
 *      Author: S-4020395
 */

#include <DoubleSolenoid.h>
#include <Subsystems/AutoCanGrabber.h>

AutoCanGrabber::AutoCanGrabber() :
		Subsystem("AutoCanGrabber") {
	solenoid = new DoubleSolenoid(AUTO_CAN_GRABBER_SOLENOID_PORT_A,
			AUTO_CAN_GRABBER_SOLENOID_PORT_B);
}

AutoCanGrabber::~AutoCanGrabber() {
	delete solenoid;
}

void AutoCanGrabber::actuate(GrabberState state) {
	switch (state) {
	case GRAB:
		solenoid->Set(DoubleSolenoid::Value::kForward);
		break;
	case RETRACT:
		solenoid->Set(DoubleSolenoid::Value::kReverse);
		break;
	default:
		//nothing?
		break;
	}
}
