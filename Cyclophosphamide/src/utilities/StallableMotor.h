/*
 * StallableMotor.h
 *
 *  Created on: Feb 10, 2015
 *      Author: Administrator
 */

#ifndef SRC_UTILITIES_STALLABLEMOTOR_H_
#define SRC_UTILITIES_STALLABLEMOTOR_H_

#include "WPILib.h"
#include <pthread.h>

class StallableMotor {
public:
	static void* StallCheck(void*);
	static void ThreadKill(pthread_t stallThread);
	static pthread_t ThreadInit(CANTalon *stallableified);
};

#endif /* SRC_UTILITIES_STALLABLEMOTOR_H_ */
