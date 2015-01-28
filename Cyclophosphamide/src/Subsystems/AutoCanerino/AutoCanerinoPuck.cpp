#include "AutoCanerinoPuck.h"
#include "../../RobotMap.h"

AutoCanerinoPuck::AutoCanerinoPuck(): Subsystem("AutoCanerinoPuck") {
	armActuate = new DoubleSolenoid(AUTO_CAN_ARM_ACTUATE);
	wench = new AUTO_CAN_MOTOR_TYPE(AUTO_CAN_WINCH);
	wenchPot = new AnalogInput(AUTO_CAN_PAAAT);
}

AutoCanerinoPuck::~AutoCanerinoPuck() {
	delete armActuate;
	delete wench;
	delete wenchPot;
}

void AutoCanerinoPuck::armDeploy() {
	armActuate->Set(DoubleSolenoid::kForward);
}

void AutoCanerinoPuck::armRetract() {
	armActuate->Set(DoubleSolenoid::kReverse);
}

void AutoCanerinoPuck::wenchSet(bool pull) {
	if (pull) {
		wench->Set(AUTO_CAN_WENCH_PULL_SPEED);
	}

	else {
		wench->Set(AUTO_CAN_WENCH_SLOW_SPEED);
	}
}

void AutoCanerinoPuck::wenchStop() {
	wench->Set(0);
}

double AutoCanerinoPuck::wenchGetPosition() {
	return wenchPot->GetAverageValue();
}
