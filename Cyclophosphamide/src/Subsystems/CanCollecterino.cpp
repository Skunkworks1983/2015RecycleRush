#include <Subsystems/CanCollecterino.h>
#include "../RobotMap.h"
#include <Math.h>
#include "../utilities/StallableMotor.h"

CanCollecterino::CanCollecterino() :
		Subsystem("CanCollecterino") {
	SAFE_INIT(CAN_MOTOR_LIFT_LEFT_PORT,
			liftMotorLeft = new CAN_MOTOR_TYPE(CAN_MOTOR_LIFT_LEFT_PORT););
	SAFE_INIT(CAN_MOTOR_LIFT_RIGHT_PORT,
			liftMotorRight = new CAN_MOTOR_TYPE(CAN_MOTOR_LIFT_RIGHT_PORT););
	SAFE_INIT(CAN_MOTOR_GRAB_LEFT_PORT,
			grabMotorLeft = new CAN_MOTOR_TYPE(CAN_MOTOR_GRAB_LEFT_PORT););
	SAFE_INIT(CAN_MOTOR_GRAB_RIGHT_PORT,
			grabMotorRight = new CAN_MOTOR_TYPE(CAN_MOTOR_GRAB_RIGHT_PORT););
	SAFE_INIT(CAN_WRIST_SOLENOID_PORT,
			wrists = new DoubleSolenoid(CAN_WRIST_SOLENOID_PORT););

	SAFE_INIT(CAN_LIFT_POT_PORT, liftPot = new AnalogInput(CAN_LIFT_POT_PORT););

	SAFE_INIT(CAN_SENSOR_PORT, canSensor = new DigitalInput(CAN_SENSOR_PORT););

	armPID = new PIDController(CAN_ARM_P, CAN_ARM_I, CAN_ARM_D, liftPot,
			new StallableMotor(liftPot, 0.8, liftMotorRight, liftMotorLeft));
	armPID->SetOutputRange(-.2, .2);
	armPID->SetInputRange(CAN_POT_DOWN_POSITION, CAN_POT_UP_POSITION);
}

CanCollecterino::~CanCollecterino() {
	delete liftMotorLeft;
	delete liftMotorRight;
	delete grabMotorLeft;
	delete grabMotorRight;
	delete wrists;
	delete canSensor;
	delete armPID;
}

void CanCollecterino::InitDefaultCommand() {

}

void CanCollecterino::StallDiag() {
	SmartDashboard::PutNumber("Output Current Left",
			grabMotorLeft->GetOutputCurrent());
	SmartDashboard::PutNumber("Output Current Right",
			grabMotorRight->GetOutputCurrent());
}

void CanCollecterino::setArms(float value) {
	setpoint = value;
	armPID->SetSetpoint(value);
	armPID->Enable();
}

void CanCollecterino::disableArms() {
	armPID->Disable();
}

void CanCollecterino::setWrist(DoubleSolenoid::Value value) {
	wrists->Set(value);
}

void CanCollecterino::setGrab(float value) {
	grabMotorLeft->Set(value);
	grabMotorRight->Set(value);
}

bool CanCollecterino::armsWithinBounds() {
	return armPID->OnTarget();
}

bool CanCollecterino::getCanSensor() {
	SmartDashboard::PutBoolean("Put Boolean", canSensor->Get());
	return canSensor->Get();
}
