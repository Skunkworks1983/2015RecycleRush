/*
 * DoubleMotorPIDOutput.h
 *
 *  Created on: Feb 4, 2015
 *      Author: S-4020395
 */

#ifndef SRC_UTILITIES_DOUBLEMOTORPIDOUTPUT_H_
#define SRC_UTILITIES_DOUBLEMOTORPIDOUTPUT_H_

#include "WPILib.h"

class DoubleMotorPIDOutput : public PIDOutput {
private:
	SpeedController *motor1, *motor2;
public:
	DoubleMotorPIDOutput(SpeedController *motor1, SpeedController *motor2);
	virtual void PIDWrite(float value);
};

#endif /* SRC_UTILITIES_DOUBLEMOTORPIDOUTPUT_H_ */
