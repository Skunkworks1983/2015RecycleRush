#include <Subsystems/CanCollecterino.h>
#include "../RobotMap.h"
#include <Math.h>
#include "../utilities/StallableMotor.h"

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
	SAFE_INIT(CAN_WRIST_SOLENOID,
			wrists = new DoubleSolenoid(CAN_WRIST_SOLENOID););

	SAFE_INIT(CAN_SENSOR, canSensor = new DigitalInput(CAN_SENSOR););

	SAFE_INIT(CAN_BRAKE, brakingRelay = new Relay(CAN_BRAKE););

//	liftMotorLeft->SetControlMode(CANSpeedController::kPosition);
//	liftMotorLeft->SetPID(CAN_ARM_P, CAN_ARM_I, CAN_ARM_D);
//	liftMotorRight->SetControlMode(CANSpeedController::kPosition);
//	liftMotorRight->SetPID(CAN_ARM_P, CAN_ARM_I, CAN_ARM_D);

	new StallableMotor(grabMotorRight, .15);
}

CanCollecterino::~CanCollecterino() {
	delete liftMotorLeft;
	delete liftMotorRight;
	delete grabMotorLeft;
	delete grabMotorRight;
	delete wrists;
	delete canSensor;

	delete brakingRelay;
}

void CanCollecterino::InitDefaultCommand() {

}

void CanCollecterino::StallDiag() {
	SmartDashboard::PutNumber("Output Current Left", grabMotorLeft->GetOutputCurrent());
	SmartDashboard::PutNumber("Output Current Right", grabMotorRight->GetOutputCurrent());
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

void CanCollecterino::setWrist(DoubleSolenoid::Value value) {
	wrists->Set(value);
}

void CanCollecterino::setGrab(float value) {
	grabMotorLeft->Set(value);
	grabMotorRight->Set(value);
}

int CanCollecterino::armsWithinBounds(float setpoint, float  bounds) {
	if (abs(liftMotorLeft->GetEncPosition()) - setpoint < bounds
				&& abs(liftMotorRight->GetEncPosition()) - setpoint < bounds) {
			return true;
		}
		return false;
}

bool CanCollecterino::getCanSensor() {
	SmartDashboard::PutBoolean("Put Boolean", canSensor->Get());
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
