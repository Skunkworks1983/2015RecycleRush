/*
 * StallableMotor.h
 *
 *  Created on: Feb 10, 2015
 *      Author: Administrator
 */

#ifndef SRC_UTILITIES_STALLABLEMOTOR_H_
#define SRC_UTILITIES_STALLABLEMOTOR_H_

#include "WPILib.h"
#include "../RobotMap.h"
#include <pthread.h>

class StallableMotor: public PIDOutput {
private:
	CANTalon *motor;
	PIDSource *input;
	pthread_t stallThread;
	float currentThreshold;
	bool stalled, usingCANTalon;

	static void *InitHelper(void *classref);
	void* StallCheck(void*);
	void ThreadInit();
	unsigned long getTime();
public:
	StallableMotor(CANTalon *motor, PIDSource *input, float currentThreshold);
	StallableMotor(CANTalon *motor, float currentThreshold);

	void ThreadKill();
	void PIDWrite(float output);
};

#endif /* SRC_UTILITIES_STALLABLEMOTOR_H_ */
