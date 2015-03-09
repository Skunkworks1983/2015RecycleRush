#include <Commands/ToteLifting/LiftToHeight.h>
#include <Commands/ToteLifting/zeroing/ZeroElevator.h>
#include <Subsystems/ToteLifterino.h>
#include "../RobotMap.h"
#include "WPILib.h"

ToteLifterino::ToteLifterino() :
		Subsystem("ToteLifterino") {
	SAFE_INIT(TOTE_LIFTER_RIGHT_PORT,
			rightMotor = new CANTalon(TOTE_LIFTER_RIGHT_PORT););
	SAFE_INIT(TOTE_LIFTER_LEFT_PORT,
			leftMotor = new CANTalon(TOTE_LIFTER_LEFT_PORT););

	SAFE_INIT(TOTE_LIFTER_ELEVATOR_TOP_INPUT_PORT,
			topInput = new DigitalInput(TOTE_LIFTER_ELEVATOR_TOP_INPUT_PORT););

	encoder = new Encoder(TOTE_LIFTER_ENCODER_PORTS);
	pid = new PIDController(TOTE_LIFTER_PID_P, TOTE_LIFTER_PID_I,
	TOTE_LIFTER_PID_D, this, this);

	pid->SetOutputRange(-0.8, 0.8);
	pid->SetInputRange(0, TOTE_LIFTER_MAX_DISTANCE);
	pid->SetPercentTolerance(.75);
	encoder->Reset();

	ignoreInput = true; //topInput->Get() && botInput->Get();
}

void ToteLifterino::InitDefaultCommand() {
}

void ToteLifterino::setZeroed(bool zeroed) {
	this->zeroed = zeroed;
}

bool ToteLifterino::getMagInput() {
	return topInput->Get();
}

CANTalon *ToteLifterino::getLeftMotor() {
	return leftMotor;
}

CANTalon *ToteLifterino::getRightMotor() {
	return rightMotor;
}

double ToteLifterino::getPosition() {
	return encoder->Get();
}

Encoder *ToteLifterino::getEncoder() {
	return encoder;
}

PIDController *ToteLifterino::getPID() {
	return pid;
}

void ToteLifterino::enablePID(bool enable) {
	if (enable && !pid->IsEnabled()) {
		pid->Enable();
	}
	if (!enable && pid->IsEnabled()) {
		pid->Disable();
	}
}

void ToteLifterino::setMotorSpeed(double speed) {
	if (speed < -1) {
		speed = -1;
	} else if (speed > 1) {
		speed = 1;
	}

	if (!ignoreInput) {
		if ((topInput->Get() && speed > 0)) {
			speed = 0;
		}
	}

	enablePID(false);
	leftMotor->Set(speed);
	rightMotor->Set(-speed);
}

void ToteLifterino::setSetPoints(double setPoint) {
	pid->SetSetpoint(setPoint);
}

bool ToteLifterino::closeEnough(float destination) {
	bool close = encoder->Get() < destination + TOTE_LIFTER_TOLERANCE
			&& encoder->Get() > destination - TOTE_LIFTER_TOLERANCE;
	SmartDashboard::PutBoolean("closeEnough", close);
	return close;
}

bool ToteLifterino::lowerThan(double height) {
	return encoder->Get() < height;
}

void ToteLifterino::PIDWrite(float f) {
	if (!ignoreInput) {
		if (topInput->Get() && f > 0) {
			f = 0;
		}
	} else {
		SmartDashboard::PutString("LifterStatus", "Ignoring Input!");
	}
//	std::cout << "PIDWrite: " <<  f << std::endl;
	leftMotor->Set(f);
	rightMotor->Set(-f);
	SmartDashboard::PutNumber("MotorValue", f);
}

double ToteLifterino::PIDGet() {
	return encoder->PIDGet();
}
