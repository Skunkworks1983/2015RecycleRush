#include <CANSpeedController.h>
#include <CANTalon.h>
#include <PIDSource.h>
#include <SmartDashboard/SmartDashboard.h>
#include <utilities/StallableMotor.h>
#include <utilities/Time.h>
#include <cstdlib>

StallableMotor::StallableMotor(PIDSource *input, float moveThreshold,
		float currentThreshold, CANTalon *motor, CANTalon *slaveMotor) {
	this->motor = motor;
	this->slaveMotor = slaveMotor;
	this->currentThreshold = currentThreshold;
	this->moveThreshold = moveThreshold;
	this->input = input;
	stalled = false;
	usingCANTalon = false;
	stalled = false;
	motor->SetControlMode(CANSpeedController::kPercentVbus);
	slaveMotor->SetControlMode(CANSpeedController::kPercentVbus);
	ThreadInit();
}

StallableMotor::StallableMotor(CANTalon *motor, float currentThreshold) {
	this->motor = motor;
	this->currentThreshold = currentThreshold;
	stalled = false;
	moveThreshold = STALLABLE_ENC_MOVE_THRESHOLD;
	usingCANTalon = true;
	stalled = false;
	ThreadInit();
}

StallableMotor::~StallableMotor() {
	delete motor;
	delete slaveMotor;
	delete input;
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
	while (true) {
		if (motor->GetOutputCurrent() > currentThreshold) {
			float currentPosition;
			if (usingCANTalon) {
				currentPosition = motor->GetEncPosition();
			} else {
				currentPosition = input->PIDGet();
			}
			if (abs(currentPosition - prevPosition) < moveThreshold) {
				SmartDashboard::PutNumber("Position Difference",
						currentPosition - prevPosition);
				if (startTime == 0) {
					startTime = Time::getTime();
				}
				double dtime = Time::getTime() - startTime;
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
			startTime = 0;
			stalled = false;
		}
	}
}

void StallableMotor::PIDWrite(float output) {
	if (!stalled) {
		motor->EnableControl();
		motor->Set(output);
		if (slaveMotor != NULL) {
			slaveMotor->EnableControl();
			slaveMotor->Set(-output);
		}
	} else if (stalled) {
		motor->Set(0);
		motor->Disable();
		if (slaveMotor != NULL) {
			slaveMotor->Set(0);
			slaveMotor->Disable();
		}
	}
}
