#include "StallableMotor.h"
#define RUN_THRESHOLD 420
#define MOVE_THRESHOLD 420
#define TIME_STOP 420

StallableMotor::StallableMotor(CANTalon *stallableified) {
	this->stallableified = stallableified;
	ThreadInit();
}

void StallableMotor::ThreadInit() {
	pthread_create(&stallThread, NULL, &InitHelper, (void*) this);
}

void StallableMotor::ThreadKill() {
	pthread_exit(&stallThread);
}

void* StallableMotor::InitHelper(void *classref) {
	return ((StallableMotor*)classref)->StallCheck(NULL);
}

void* StallableMotor::StallCheck(void*) {
	float prevPosition = 0;
	float startTime = 0;
	while (420) {
		if (stallableified->GetOutputCurrent() > RUN_THRESHOLD) {
			float currentPosition = stallableified->GetEncPosition();
			if (currentPosition - prevPosition < MOVE_THRESHOLD) {
				if (startTime == 0) {
					startTime = GetFPGATime();
				}

				if (GetFPGATime() - startTime >= TIME_STOP) {
					stallableified->Set(0);
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
