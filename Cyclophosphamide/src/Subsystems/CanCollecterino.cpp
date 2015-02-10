#include <Subsystems/CanCollecterino.h>
#include "../RobotMap.h"
#include <Math.h>

CanCollecterino::CanCollecterino() :
		Subsystem("CanCollecterino") {
	SAFE_INIT(CAN_MOTOR_LIFT_LEFT,
			liftMotorLeft = new CAN_MOTOR_TYPE(CAN_MOTOR_LIFT_LEFT););
	SAFE_INIT(CAN_MOTOR_LIFT_RIGHT,
			liftMotorRight = new CAN_MOTOR_TYPE(CAN_MOTOR_LIFT_RIGHT););
	SAFE_INIT(CAN_MOTOR_GRAB_LEFT,
			grabMotorLeft = new CAN_MOTOR_TYPE(CAN_MOTOR_GRAB_LEFT););
	SAFE_INIT(CAN_MOTOR_GRAB_RIGHT,
			grabMotorRight = new CAN_MOTOR_TYPE(CAN_MOTOR_GRAB_RIGHT););
	SAFE_INIT(CAN_MOTOR_WRIST_LEFT,
			wristMotorLeft = new CAN_MOTOR_TYPE(CAN_MOTOR_WRIST_LEFT););
	SAFE_INIT(CAN_MOTOR_WRIST_RIGHT,
			wristMotorRight = new CAN_MOTOR_TYPE(CAN_MOTOR_WRIST_RIGHT););

	SAFE_INIT(CAN_SENSOR, canSensor = new DigitalInput(CAN_SENSOR););

	SAFE_INIT(CAN_BRAKE, brakingRelay = new Relay(CAN_BRAKE););
//	liftMotorLeft->SetPID(CAN_ARM_P, CAN_ARM_I, CAN_ARM_D);
//	liftMotorRight->SetPID(CAN_ARM_P, CAN_ARM_I, CAN_ARM_D);
}

CanCollecterino::~CanCollecterino() {
	delete liftMotorLeft;
	delete liftMotorRight;
	delete grabMotorLeft;
	delete grabMotorRight;
	delete wristMotorLeft;
	delete wristMotorRight;

	delete canSensor;

	delete brakingRelay;
}

void CanCollecterino::InitDefaultCommand() {

}

void CanCollecterino::setArms(float value) {
	brakeArms(false);
	liftMotorLeft->SetPosition(0);
	liftMotorRight->SetPosition(0);

	liftMotorLeft->EnableControl();
	liftMotorRight->EnableControl();
	liftMotorLeft->PIDWrite(value);
	liftMotorRight->PIDWrite(value);
}

void CanCollecterino::disableArms() {
	liftMotorLeft->Disable();
	liftMotorRight->Disable();
	brakeArms(true);
}

bool CanCollecterino::wristWithinBounds(float setpoint, float bounds) {
	if (abs(wristMotorLeft->GetEncPosition()) - setpoint < bounds
			&& abs(wristMotorRight->GetEncPosition()) - setpoint < bounds) {
		return true;
	}
	return false;
}

void CanCollecterino::setWrist(float value) {
	if (value == 0) {
		wristMotorLeft->Disable();
		wristMotorRight->Disable();
	}
	else {
		wristMotorLeft->Set(value);
		wristMotorRight->Set(value);
	}
}

void CanCollecterino::setGrab(float value) {
	if (value == 0) {
		grabMotorLeft->Disable();
		grabMotorRight->Disable();
	}
	else {
		grabMotorLeft->Set(value);
		grabMotorRight->Set(value);
	}
}

int CanCollecterino::armsWithinBounds(float setpoint, float  bounds) {
	if (abs(liftMotorLeft->GetEncPosition()) - setpoint < bounds
				&& abs(liftMotorRight->GetEncPosition()) - setpoint < bounds) {
			return true;
		}
		return false;
}

bool CanCollecterino::getCanSensor() {
	return canSensor->Get();
}

void CanCollecterino::brakeArms(bool brake) {
	if (brake) {
		disableArms();
		brakingRelay->Set(Relay::kOff);
	}

	else {
		brakingRelay->Set(Relay::kOn);
	}
}
