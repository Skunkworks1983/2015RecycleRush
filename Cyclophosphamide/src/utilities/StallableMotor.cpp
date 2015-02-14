#include "StallableMotor.h"

StallableMotor::StallableMotor(CANTalon *motor, PIDSource *input,
		float currentThreshold) {
	this->motor = motor;
	this->currentThreshold = currentThreshold;
	this->input = input;
	usingCANTalon = false;
	ThreadInit();
}

StallableMotor::StallableMotor(CANTalon *motor, float currentThreshold) {
	this->motor = motor;
	this->currentThreshold = currentThreshold;
	usingCANTalon = true;
	ThreadInit();
}

void StallableMotor::ThreadInit() {
	pthread_create(&stallThread, NULL, &InitHelper, (void*) this);
}

void StallableMotor::ThreadKill() {
	pthread_exit(&stallThread);
}

void* StallableMotor::InitHelper(void *classref) {
	return ((StallableMotor*) classref)->StallCheck(NULL);
}

void* StallableMotor::StallCheck(void*) {
	float prevPosition = 0;
	float startTime = 0;
	while (420) {
		if (motor->GetOutputCurrent() > currentThreshold) {
			float currentPosition;
			if (usingCANTalon) {
				currentPosition = input->PIDGet();
			} else {
				currentPosition = motor->GetEncPosition();
			}
			if (currentPosition - prevPosition < STALLABLE_MOVE_THRESHOLD) {
				SmartDashboard::PutNumber("Position Difference",
						currentPosition - prevPosition);
				if (startTime == 0) {
					startTime = getTime();
				}
				double dtime = getTime() - startTime;
				SmartDashboard::PutNumber("Stall Time", dtime);
				if (dtime >= STALLABLE_TIME_STOP) {
					stalled = true;
				}
			} else {
				if (startTime != 0) {
					startTime = 0;
					stalled = false;
				}
			}
			prevPosition = currentPosition;
		} else {
			if (startTime != 0) {
				startTime = 0;
				stalled = false;
			}
		}
	}
}

void StallableMotor::PIDWrite(float output) {
	if (!stalled) {
		motor->Set(output);
	} else {
		motor->SetControlMode(CANSpeedController::kPercentVbus);
		motor->Set(0);
		motor->Disable();
	}
}

unsigned long StallableMotor::getTime() {
	using namespace std::chrono;
	unsigned long ms = duration_cast<milliseconds>(
			high_resolution_clock::now().time_since_epoch()).count();
	return ms;
}
