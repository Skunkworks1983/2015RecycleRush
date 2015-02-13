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

class StallableMotor {
private:
	CANTalon *stallableified;
	pthread_t stallThread;
	float currentThreshold;

	static void *InitHelper(void *classref);
	void* StallCheck(void*);
	void ThreadInit();
	unsigned long getTime();

public:
	StallableMotor(CANTalon *stallablefied, float currentThreshold);
	void ThreadKill();
};

#endif /* SRC_UTILITIES_STALLABLEMOTOR_H_ */
