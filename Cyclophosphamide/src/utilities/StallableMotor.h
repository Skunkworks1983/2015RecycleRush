#ifndef SRC_UTILITIES_STALLABLEMOTOR_H_
#define SRC_UTILITIES_STALLABLEMOTOR_H_

#include "WPILib.h"
#include "../RobotMap.h"
#include <pthread.h>

class StallableMotor: public PIDOutput {
private:
	CANTalon *motor;
	CANTalon *slaveMotor;
	PIDSource *input;
	pthread_t stallThread;
	int directionMag, pdirectionMag;
	float currentThreshold;
	bool stalled, usingCANTalon, directionSwitch, stalledStart;

	static void *InitHelper(void *classref);
	void* StallCheck(void*);
	void ThreadInit();
	unsigned long getTime();
public:
	StallableMotor(PIDSource *input, float currentThreshold, CANTalon *motor, CANTalon *slaveMotor= NULL);
	StallableMotor(CANTalon *motor, float currentThreshold);
	~StallableMotor();

	void ThreadKill();
	void PIDWrite(float output);
};

#endif /* SRC_UTILITIES_STALLABLEMOTOR_H_ */
