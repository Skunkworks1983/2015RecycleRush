/*
 * MoveUntilTotes.cpp
 *
 *  Created on: Mar 22, 2015
 *      Author: s-4020395
 */

#include <Commands/Automatic/MoveUntilForce.h>
#include <interfaces/Accelerometer.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Subsystems/DriveBae.h>

MoveUntilForce::MoveUntilForce(double speed, double gForce, ForceAxis axis) :
		CommandBase("Move Until Totes") {
	Requires(driveBae);
	this->speed = speed;
	this->gForce = gForce;
	this->axis = axis;
	measuredMax = 0;
}

MoveUntilForce::~MoveUntilForce() {
}

// Called just before this Command runs the first time
void MoveUntilForce::Initialize() {
	SmartDashboard::PutNumber("MoveUntilForceSpeed", -speed);
	driveBae->setSpeed(-speed, -speed, -speed, -speed);
}

// Called repeatedly when this Command is scheduled to run
void MoveUntilForce::Execute() {
	// ayy lma0
	switch (axis) {
	case X:
		measuredMax =
				measuredMax > driveBae->getBuiltInAccel()->GetX() ?
						driveBae->getBuiltInAccel()->GetX() : measuredMax;
		break;
	case Y:
		measuredMax =
				measuredMax > driveBae->getBuiltInAccel()->GetY() ?
						driveBae->getBuiltInAccel()->GetY() : measuredMax;
		break;
	case Z:
		measuredMax =
				measuredMax > driveBae->getBuiltInAccel()->GetZ() ?
						driveBae->getBuiltInAccel()->GetZ() : measuredMax;
		break;
	}
	SmartDashboard::PutNumber("MaxGForce", measuredMax);
}

// Make this return true when this Command no longer needs to run execute()
bool MoveUntilForce::IsFinished() {
	switch (axis) {
	case X:
		return driveBae->getBuiltInAccel()->GetX() <= gForce;
	case Y:
		return driveBae->getBuiltInAccel()->GetY() <= gForce;
	case Z:
		return driveBae->getBuiltInAccel()->GetZ() <= gForce;
	}
	return false;
}

// Called once after isFinished returns true
void MoveUntilForce::End() {
	driveBae->setAll(0);
	driveBae->setSpeed(0, 0, 0, 0);
	driveBae->enablePIDAll(false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveUntilForce::Interrupted() {
	End();
}
