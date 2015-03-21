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
	float currentThreshold, moveThreshold;
	bool stalled, usingCANTalon;

	static void *InitHelper(void *classref);
	void* StallCheck(void*);
	void ThreadInit();
public:
	StallableMotor(PIDSource *input, float moveThreshold,
			float currentThreshold, CANTalon *motor,
			CANTalon *slaveMotor = NULL);
	StallableMotor(CANTalon *motor, float currentThreshold);
	~StallableMotor();

	void ThreadKill();
	void PIDWrite(float output);
};

#endif /* SRC_UTILITIES_STALLABLEMOTOR_H_ */
