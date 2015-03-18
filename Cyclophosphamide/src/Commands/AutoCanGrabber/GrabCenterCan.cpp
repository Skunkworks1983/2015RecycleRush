/*
 * GrabCenterCan.cpp
 *
 *  Created on: Mar 18, 2015
 *      Author: S-4020395
 */

#include <Commands/AutoCanGrabber/GrabCenterCan.h>

GrabCenterCan::GrabCenterCan(AutoCanGrabber::GrabberState state) {
	Requires(autoCanGrabber);
	this->state = state;
}

GrabCenterCan::~GrabCenterCan() {

}

void GrabCenterCan::Initialize() {
	autoCanGrabber->actuate(state);
}

void GrabCenterCan::Execute() {

}

bool GrabCenterCan::IsFinished() {
	return true;
}

void GrabCenterCan::End() {

}

void GrabCenterCan::Interrupted() {

}
