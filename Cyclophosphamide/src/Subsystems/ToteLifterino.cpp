#include <Subsystems/ToteLifterino.h>
#include "../RobotMap.h"
#include "../Commands/ToteHandling/LiftToHeight.h"
#include "WPILib.h"

ToteLifterino::ToteLifterino() :
		Subsystem("ToteLifterino") {
//	lift_traveled_sensor = new DigitalInput(TOTE_LIFTER_SENSOR);
	SAFE_INIT(TOTE_LIFTER_RIGHT, rightMotor = new Talon(TOTE_LIFTER_RIGHT););
	SAFE_INIT(TOTE_LIFTER_LEFT, leftMotor = new Talon(TOTE_LIFTER_LEFT););
	//SAFE_INIT(TOTE_LIFTER_TOTE_INPUT,
	//		toteUnderInput = new DigitalInput(TOTE_LIFTER_TOTE_INPUT););
	//elevatorTopInput = new DigitalInput(TOTE_LIFTER_ELEVATOR_TOP_INPUT_PORT);
	encoder = new Encoder(TOTE_LIFTER_ENCODER_PORTS);
	pid = new DoubleMotorPIDWrapper(TOTE_LIFTER_PID_P, TOTE_LIFTER_PID_I,
			TOTE_LIFTER_PID_D, leftMotor,rightMotor, encoder);

	SmartDashboard::PutNumber("P", TOTE_LIFTER_PID_P);
	SmartDashboard::PutNumber("I", TOTE_LIFTER_PID_I);
	SmartDashboard::PutNumber("D", TOTE_LIFTER_PID_D);

	encoder->Reset();
}

double ToteLifterino::getEncPosition(){
	return encoder->GetDistance();
}

void ToteLifterino::InitDefaultCommand() {
	SetDefaultCommand(new LiftToHeight(TOTE_LIFTER_FLOOR));
}

bool ToteLifterino::getElevatorDigitalInput() {
	return elevatorTopInput->Get();
}

Talon *ToteLifterino::getLeftMotor() {
	return leftMotor;
}

Talon *ToteLifterino::getRightMotor() {
	return rightMotor;
}

bool ToteLifterino::isToteUnder() {
	return toteUnderInput->Get();
}

void ToteLifterino::enablePID(bool enable) {
	pidEnabled = enable;
	if (pidEnabled) {
		pid->setPID(TOTE_LIFTER_PID_P, TOTE_LIFTER_PID_I,
		TOTE_LIFTER_PID_D);

		pid->enable(true);
	} else {
		pid->enable(false);
	}
}

DoubleMotorPIDWrapper *ToteLifterino::getPID(){
	return pid;
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
	//rightMotor->Set(setPoint * TOTE_LIFTER_TICKS_PER_INCH);
	leftMotor->Set(setPoint * TOTE_LIFTER_TICKS_PER_INCH);
}
