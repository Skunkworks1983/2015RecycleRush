#ifndef COLLECTERINO_INTAKERINO_H
#define COLLECTERINO_INTAKERINO_H
/*!
 * 2 motors to run the wheels, and intake/expell the can.
 *
 */

#include "WPILib.h"
#include "RobotMap.h"

/*!
 *the wheels spin to intake or expell the recycle bin.
 */
class CanIntakerino: public Subsystem {
private:
	CAN_MOTOR_TYPE *grabMotorLeft;CAN_MOTOR_TYPE *grabMotorRight;

public:
	CanIntakerino();
	~CanIntakerino();

	void setGrab(float value);
};

#endif
