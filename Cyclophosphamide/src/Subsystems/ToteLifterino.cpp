#include <Subsystems/ToteLifterino.h>
#include "../RobotMap.h"
#include "../Commands/ToteHandling/LiftToHeight.h"
#include "../Commands/ToteHandling/ZeroElevator.h"
#include "WPILib.h"

ToteLifterino::ToteLifterino() :
		Subsystem("ToteLifterino") {
	SAFE_INIT(TOTE_LIFTER_RIGHT_PORT,
			rightMotor = new CANTalon(TOTE_LIFTER_RIGHT_PORT););
	SAFE_INIT(TOTE_LIFTER_LEFT_PORT,
			leftMotor = new CANTalon(TOTE_LIFTER_LEFT_PORT););

	SAFE_INIT(TOTE_LIFTER_ELEVATOR_TOP_INPUT_PORT,
			topInput = new DigitalInput(TOTE_LIFTER_ELEVATOR_TOP_INPUT_PORT););

	SAFE_INIT(TOTE_LIFTER_ELEVATOR_BOT_INPUT_PORT,
			botInput = new DigitalInput(TOTE_LIFTER_ELEVATOR_BOT_INPUT_PORT););

	encoder = new Encoder(TOTE_LIFTER_ENCODER_PORTS);
	pid = new PIDController(TOTE_LIFTER_PID_P, TOTE_LIFTER_PID_I,
	TOTE_LIFTER_PID_D, this, this);

	pid->SetOutputRange(-0.8, 0.8);
	pid->SetInputRange(0, TOTE_LIFTER_MAX_DISTANCE);
	pid->SetPercentTolerance(.75);
	encoder->Reset();

	ignoreInput = true; //topInput->Get() && botInput->Get();

	notZeroed = !botInput->Get();
}

void ToteLifterino::InitDefaultCommand() {
	if (notZeroed) {
		//SetDefaultCommand(new ZeroElevator(true));
	} else {
		SetDefaultCommand(NULL);
	}
}

void ToteLifterino::setZeroed(bool zeroed) {
	notZeroed = !zeroed;
}

bool ToteLifterino::getTopInput() {
	return topInput->Get();
}

bool ToteLifterino::getBotInput() {
	return botInput->Get();
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
		if ((topInput->Get() && speed > 0) || (botInput->Get() && speed < 0)) {
			speed = 0;
		}
	}

	enablePID(false);
	leftMotor->Set(speed);
	rightMotor->Set(-speed);
}

bool ToteLifterino::isCoop() {
	return coopState;
}

void ToteLifterino::setCoop(bool isCoop) {
	this->coopState = isCoop;
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

void ToteLifterino::WatchDogg() {
	//check if digitalinputs are broken
	ignoreInput = (botInput->Get() && topInput->Get());

	//check if encoder is broken
	if (!notZeroed) {
		SetDefaultCommand(NULL);
	}
}

void ToteLifterino::PIDWrite(float f) {
	if (!ignoreInput) {
		if ((topInput->Get() && f > 0) || (botInput->Get() && f < 0)) {
			f = 0;
		}
	} else {
		SmartDashboard::PutString("LifterStatus", "Ignoring Input!");
	}
	leftMotor->Set(f);
	rightMotor->Set(-f);
	SmartDashboard::PutNumber("MotorValue", f);
}

double ToteLifterino::PIDGet() {
	return encoder->PIDGet();
}
