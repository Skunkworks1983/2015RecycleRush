#include <Subsystems/ToteLifterino.h>
#include "../RobotMap.h"
#include "../Commands/ToteHandling/LiftToHeight.h"
#include "WPILib.h"

ToteLifterino::ToteLifterino() :
		Subsystem("ToteLifterino") {
//	lift_traveled_sensor = new DigitalInput(TOTE_LIFTER_SENSOR);
	SAFE_INIT(TOTE_LIFTER_RIGHT, rightMotor = new CANTalon(TOTE_LIFTER_RIGHT););
	SAFE_INIT(TOTE_LIFTER_LEFT, leftMotor = new CANTalon(TOTE_LIFTER_LEFT););
	//SAFE_INIT(TOTE_LIFTER_TOTE_INPUT,
	//		toteUnderInput = new DigitalInput(TOTE_LIFTER_TOTE_INPUT););
	//elevatorTopInput = new DigitalInput(TOTE_LIFTER_ELEVATOR_TOP_INPUT_PORT);
	encoder = new Encoder(TOTE_LIFTER_ENCODER_PORTS);
	pid = new PIDController(TOTE_LIFTER_PID_P, TOTE_LIFTER_PID_I,
			TOTE_LIFTER_PID_D, encoder, this);

	SmartDashboard::PutNumber("P", TOTE_LIFTER_PID_P);
	SmartDashboard::PutNumber("I", TOTE_LIFTER_PID_I);
	SmartDashboard::PutNumber("D", TOTE_LIFTER_PID_D);

	pid->SetOutputRange(-1.0, 1.0);
	encoder->Reset();
}

void ToteLifterino::InitDefaultCommand() {
	SetDefaultCommand(new LiftToHeight(TOTE_LIFTER_FLOOR));
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
	if (enable) {
		pid->Enable();
		encoder->Reset();
	} else {
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
	pid->SetSetpoint(setPoint * TOTE_LIFTER_TICKS_PER_INCH);
}

void ToteLifterino::PIDWrite(float f) {
	leftMotor->Set(f);
	rightMotor->Set(-f);
}

double ToteLifterino::PIDGet() {
	return encoder->Get();
}

