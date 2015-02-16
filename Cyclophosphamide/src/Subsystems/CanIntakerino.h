#ifndef COLLECTERINO_INTAKERINO_H
#define COLLECTERINO_INTAKERINO_H

#include "WPILib.h"
#include "RobotMap.h"

class CanIntakerino: public Subsystem
{
private:
	CAN_MOTOR_TYPE *grabMotorLeft;
	CAN_MOTOR_TYPE *grabMotorRight;

public:
	CanIntakerino();
	~CanIntakerino();

	void setGrab(float value);
};

#endif
