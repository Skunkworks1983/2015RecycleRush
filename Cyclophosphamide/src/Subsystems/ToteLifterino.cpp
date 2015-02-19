#include <Subsystems/ToteLifterino.h>
#include "../RobotMap.h"
#include "../Commands/ToteHandling/LiftToHeight.h"
#include "WPILib.h"

ToteLifterino::ToteLifterino() :
		Subsystem("ToteLifterino") {

	SAFE_INIT(TOTE_LIFTER_RIGHT_PORT,
			rightMotor = new CANTalon(TOTE_LIFTER_RIGHT_PORT););
	SAFE_INIT(TOTE_LIFTER_LEFT_PORT,
			leftMotor = new CANTalon(TOTE_LIFTER_LEFT_PORT););

	encoder = new Encoder(TOTE_LIFTER_ENCODER_PORTS);
	pid = new PIDController(TOTE_LIFTER_PID_P, TOTE_LIFTER_PID_I,
	TOTE_LIFTER_PID_D, this, this);

	pid->SetOutputRange(-0.8, 0.8);
	pid->SetInputRange(0, TOTE_LIFTER_MAX_DISTANCE);
	pid->SetPercentTolerance(.75);
	encoder->Reset();
}

void ToteLifterino::InitDefaultCommand() {
	//SetDefaultCommand(new LiftToHeight(TOTE_LIFTER_FLOOR_HEIGHT));
}

bool ToteLifterino::getElevatorDigitalInput() {
	return elevatorTopInput->Get();
}

CANTalon *ToteLifterino::getLeftMotor() {
	return leftMotor;
}

CANTalon *ToteLifterino::getRightMotor() {
	return rightMotor;
}

float ToteLifterino::getPosition() {
	return encoder->Get();
}

Encoder *ToteLifterino::getEncoder() {
	return encoder;
}

PIDController *ToteLifterino::getPID() {
	return pid;
}

bool ToteLifterino::isToteUnder() {
	return toteUnderInput->Get();
}

void ToteLifterino::enablePID(bool enable) {
	if (enable && !pid->IsEnabled()) {
		pid->Enable();
	}
	if (!enable && pid->IsEnabled()) {
		pid->Disable();
	}
}

//disables the pid
void ToteLifterino::setMotorSpeed(double speed) {
	if (speed < -1) {
		speed = -1;
	} else if (speed > 1) {
		speed = 1;
	}
	enablePID(false);
	leftMotor->Set(speed);
	rightMotor->Set(-speed);

}

void ToteLifterino::setSetPoints(double setPoint) {
	pid->SetSetpoint(setPoint);
}

bool ToteLifterino::closeEnough(float destination) {
	return abs(destination - encoder->Get()) < TOTE_LIFTER_BANGBANG_TOLERANCE;
}

void ToteLifterino::PIDWrite(float f) {
	leftMotor->Set(f);
	rightMotor->Set(-f);

}

double ToteLifterino::PIDGet() {
	return encoder->PIDGet();
}
