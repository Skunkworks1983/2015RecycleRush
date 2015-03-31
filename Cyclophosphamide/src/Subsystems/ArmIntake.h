#ifndef COLLECTERINO_INTAKERINO_H
#define COLLECTERINO_INTAKERINO_H

#include "WPILib.h"
#include "RobotMap.h"
/**
 * Subsystem Controlling the "hand" motors on the can collection Mechanum arms.
 *  Needed to be separate than the other parts due to Requires conflicts when running at same time.
 */
class ArmIntake: public Subsystem {
private:
	CAN_MOTOR_TYPE *grabMotorLeft;CAN_MOTOR_TYPE *grabMotorRight;

public:
	ArmIntake();
	~ArmIntake();

	void setGrab(float value);CAN_MOTOR_TYPE *getLeft();CAN_MOTOR_TYPE *getRight();
};

#endif
