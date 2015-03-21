/*
 * RampRampInduct.cpp
 *
 *  Created on: Mar 21, 2015
 *      Author: s-4020395
 */

#include <Commands/Armerino/Arms/RampInduct.h>
#include <Subsystems/ArmIntakerino.h>
#include <utilities/Time.h>

#define NO_MOVE_SPEED .5

RampInduct::RampInduct(float maxSpeed, double time) {
	Requires(armIntakerino);
	this->maxSpeed = maxSpeed;
	this->time = time * 1000;
}

void RampInduct::Initialize() {
	this->startTime = Time::getTime();
}

void RampInduct::Execute() {
	currentTime = Time::getTime();
	armIntakerino->setGrab(
			!isRamped ?
					(((currentTime - startTime) / time)
							* (maxSpeed - NO_MOVE_SPEED) + NO_MOVE_SPEED) :
					maxSpeed);
}

bool RampInduct::IsFinished() {
	return false;
}

void RampInduct::End() {
	armIntakerino->setGrab(0);
}

void RampInduct::Interrupted() {
	armIntakerino->setGrab(0);
}

