#include <Subsystems/CanCollecterino.h>
#include "../RobotMap.h"

CanCollecterino::CanCollecterino() :
		Subsystem("CanCollecterino") {
	SAFE_INIT(CAN_MOTOR_LIFT_LEFT, liftMotorLeft = new CAN_MOTOR_TYPE(CAN_MOTOR_LIFT_LEFT););
	SAFE_INIT(CAN_MOTOR_LIFT_RIGHT, liftMotorRight = new CAN_MOTOR_TYPE(CAN_MOTOR_LIFT_RIGHT););
	SAFE_INIT(CAN_MOTOR_GRAB_LEFT, grabMotorLeft = new CAN_MOTOR_TYPE(CAN_MOTOR_GRAB_LEFT););
	SAFE_INIT(CAN_MOTOR_GRAB_RIGHT, grabMotorRight = new CAN_MOTOR_TYPE(CAN_MOTOR_GRAB_RIGHT););

	SAFE_INIT(CAN_SENSOR, canSensor = new DigitalInput(CAN_SENSOR););

	SAFE_INIT(CAN_POT_LIFT_LEFT, liftPotLeft = new AnalogInput(CAN_POT_LIFT_LEFT););
	SAFE_INIT(CAN_POT_LIFT_RIGHT, liftPotRight = new AnalogInput(CAN_POT_LIFT_RIGHT););

	SAFE_INIT(CAN_BRAKE, brakingRelay = new Relay(CAN_BRAKE););
}

CanCollecterino::~CanCollecterino() {
	delete liftMotorLeft;
	delete liftMotorRight;
	delete grabMotorLeft;
	delete grabMotorRight;

	delete canSensor;

	delete liftPotLeft;
	delete liftPotRight;

	delete brakingRelay;
}

void CanCollecterino::expel() {
	grabMotorLeft->Set(1.0);
	grabMotorRight->Set(1.0);
}

void CanCollecterino::induct() {
	grabMotorLeft->Set(-1.0);
	grabMotorRight->Set(-1.0);
}

void CanCollecterino::rest() {
	grabMotorLeft->Set(0.0);
	grabMotorRight->Set(0.0);
}

int CanCollecterino::getPotValue() {
	return (liftPotLeft->GetValue() + liftPotRight->GetValue()) / 2;
}

bool CanCollecterino::getCanSensor() {
	return canSensor->Get();
}

void CanCollecterino::moveDownPosition() {
	liftMotorLeft->Set(-1.0);
	liftMotorRight->Set(-1.0);
}

void CanCollecterino::moveUpPosition() {
	liftMotorLeft->Set(1.0);
	liftMotorRight->Set(1.0);
}

void CanCollecterino::brakeArms(bool brake) {
	if (brake) {
		liftMotorLeft->Set(0.0);
		liftMotorRight->Set(0.0);
		brakingRelay->Set(Relay::kOff);
	}

	else {
		brakingRelay->Set(Relay::kOn);
	}
}
