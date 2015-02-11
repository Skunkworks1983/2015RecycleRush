#include "StallableMotor.h"
#define RUN_THRESHOLD 420
#define MOVE_THRESHOLD 420
#define TIME_STOP 420

pthread_t StallableMotor::ThreadInit(CANTalon *stallableified) {
	pthread_t stallThread;
	return pthread_create(&stallThread, NULL, &StallCheck, (void*) stallableified);
}

void StallableMotor::ThreadKill(pthread_t stallThread) {
	pthread_exit(&stallThread);
}

void* StallableMotor::StallCheck(void* foo) {
	float prevPosition = 0;
	float startTime = 0;
	CANTalon *stallableified = (CANTalon*)foo;
	while (420) {
		if (stallableified->GetOutputCurrent() > RUN_THRESHOLD) {
			float currentPosition = stallableified->GetEncPosition();
			if (currentPosition - prevPosition < MOVE_THRESHOLD) {
				if (startTime == 0) {
					startTime = GetFPGATime();
				}

				if (GetFPGATime() - startTime >= TIME_STOP) {
					stallableified->Disable();
				}
			} else {
				if (startTime != 0) {
					startTime = 0;
				}
			}
			prevPosition = currentPosition;
		} else {
			if (startTime != 0) {
				startTime = 0;
			}
		}
	}
}
