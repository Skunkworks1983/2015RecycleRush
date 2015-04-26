/*
 * RampRampInduct.cpp
 *
 *  Created on: Mar 21, 2015
 *      Author: s-4020395
 */

#include <Commands/Automatic/RampTimedDrive.h>
#include <Subsystems/ArmIntake.h>
#include <Subsystems/DriveBase.h>
#include <utilities/Time.h>
#include <Math.h>

#define NO_MOVE_SPEED .5
#define MAX 1

RampTimedDrive::RampTimedDrive(float desiredSpeed, double time) {
	Requires(driveBase);
	SetTimeout(time);
	this->desiredSpeed = desiredSpeed;
	this->time = time * 1000;
	value = 1.0;
}

void RampTimedDrive::Initialize() {
	this->startTime = Time::getTime();
}

void RampTimedDrive::Execute() {
	currentTime = Time::getTime();
	if(currentTime - startTime > 350){
		value = .4;
	}
//	double value = 0.6
//			- ((currentTime / 750) * (currentTime / 750) * (currentTime / 750)
//					* .6) + 0.4;
	driveBase->setForward(value);
	driveBase->execute();
}

bool RampTimedDrive::IsFinished() {
	return IsTimedOut();
}

void RampTimedDrive::End() {
	armIntake->setGrab(0);
}

void RampTimedDrive::Interrupted() {
	armIntake->setGrab(0);
}

