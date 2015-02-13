#include "StallableMotor.h"

StallableMotor::StallableMotor(CANTalon *stallableified, float currentThreshold) {
	this->stallableified = stallableified;
	this->currentThreshold = currentThreshold;
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
		if (stallableified->GetOutputCurrent() > currentThreshold) {
			float currentPosition = stallableified->GetEncPosition();
			if (currentPosition - prevPosition < STALLABLE_MOVE_THRESHOLD) {
				SmartDashboard::PutNumber("Position Difference", currentPosition - prevPosition);
				if (startTime == 0) {
					startTime = getTime();
				}
				double dtime = getTime() - startTime;
				SmartDashboard::PutNumber("Stall Time", dtime);
				if (dtime >= STALLABLE_TIME_STOP) {
					stallableified->SetControlMode(CANSpeedController::kPercentVbus);
					stallableified->Set(0);
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

unsigned long StallableMotor::getTime() {
	using namespace std::chrono;
	unsigned long ms = duration_cast<milliseconds>(
			high_resolution_clock::now().time_since_epoch()).count();
	return ms;
}
