#ifndef COLLECTERINO_INTAKERINO_H
#define COLLECTERINO_INTAKERINO_H

#include "WPILib.h"
#include "RobotMap.h"
/**
 * left and right motor setting value.
 */
class ArmIntakerino: public Subsystem {
private:
	CAN_MOTOR_TYPE *grabMotorLeft;CAN_MOTOR_TYPE *grabMotorRight;

public:
	ArmIntakerino();
	~ArmIntakerino();

	void setGrab(float value);
};

#endif
