/*
 * MoveUntilTotes.cpp
 *
 *  Created on: Mar 22, 2015
 *      Author: s-4020395
 */

#include <Commands/Automatic/MoveUntilForce.h>
#include <interfaces/Accelerometer.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Subsystems/DriveBase.h>

MoveUntilForce::MoveUntilForce(double speed, double gForce, ForceAxis axis) :
		CommandBase("Move Until Totes") {
	Requires(driveBase);
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
	driveBase->setSpeed(-speed, -speed, -speed, -speed);
}

// Called repeatedly when this Command is scheduled to run
void MoveUntilForce::Execute() {
	// ayy lma0
	switch (axis) {
	case X:
		measuredMax =
				measuredMax > driveBase->getBuiltInAccel()->GetX() ?
						driveBase->getBuiltInAccel()->GetX() : measuredMax;
		break;
	case Y:
		measuredMax =
				measuredMax > driveBase->getBuiltInAccel()->GetY() ?
						driveBase->getBuiltInAccel()->GetY() : measuredMax;
		break;
	case Z:
		measuredMax =
				measuredMax > driveBase->getBuiltInAccel()->GetZ() ?
						driveBase->getBuiltInAccel()->GetZ() : measuredMax;
		break;
	}
	SmartDashboard::PutNumber("MaxGForce", measuredMax);
}

// Make this return true when this Command no longer needs to run execute()
bool MoveUntilForce::IsFinished() {
	switch (axis) {
	case X:
		return driveBase->getBuiltInAccel()->GetX() <= gForce;
	case Y:
		return driveBase->getBuiltInAccel()->GetY() <= gForce;
	case Z:
		return driveBase->getBuiltInAccel()->GetZ() <= gForce;
	}
	return false;
}

// Called once after isFinished returns true
void MoveUntilForce::End() {
	driveBase->setAll(0);
	driveBase->setSpeed(0, 0, 0, 0);
	driveBase->enablePIDAll(false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveUntilForce::Interrupted() {
	End();
}
