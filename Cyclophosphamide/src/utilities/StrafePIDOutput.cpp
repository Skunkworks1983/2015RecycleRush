/*
 * StrafePIDOutput.cpp
 *
 *  Created on: Mar 4, 2015
 *      Author: s-4020395
 */

#include <Subsystems/DriveBae.h>
#include <utilities/StrafePIDOutput.h>
#include <Vision/VisionRunner.h>

StrafePIDOutput::StrafePIDOutput(DriveBae *driveBae) {
	this->driveBae = driveBae;
}

StrafePIDOutput::~StrafePIDOutput() {
}

void StrafePIDOutput::PIDWrite(float output) {
	driveBae->setRight(
			output / (VisionRunner::getInstance().getXResolution() / 2));
}
