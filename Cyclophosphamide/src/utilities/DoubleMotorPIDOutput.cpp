/*
 * DoubleMotorPIDOutput.cpp
 *
 *  Created on: Feb 4, 2015
 *      Author: S-4020395
 */

#include <utilities/DoubleMotorPIDOutput.h>

DoubleMotorPIDOutput::DoubleMotorPIDOutput(SpeedController *motor1,
		SpeedController *motor2) {
	this->motor1 = motor1;
	this->motor2 = motor2;
}

void DoubleMotorPIDOutput::PIDWrite(float value) {
	motor1->PIDWrite(value);
	motor2->PIDWrite(value);
}
