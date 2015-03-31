#include <CANTalon.h>
#include <DigitalInput.h>
#include <Encoder.h>
#include <PIDController.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Subsystems/ToteLifter.h>

ToteLifter::ToteLifter() :
		Subsystem("ToteLifterino") {
	SAFE_INIT(TOTE_LIFTER_RIGHT_PORT,
			rightMotor = new CANTalon(TOTE_LIFTER_RIGHT_PORT););
	SAFE_INIT(TOTE_LIFTER_LEFT_PORT,
			leftMotor = new CANTalon(TOTE_LIFTER_LEFT_PORT););

	SAFE_INIT(TOTE_LIFTER_ELEVATOR_INPUT_PORT,
			elevatorInput = new DigitalInput(TOTE_LIFTER_ELEVATOR_INPUT_PORT););
	SAFE_INIT(TOTE_LIFTER_CRAAAW_INPUT_PORT,
			craaawInput = new DigitalInput(TOTE_LIFTER_CRAAAW_INPUT_PORT););

	encoder = new Encoder(TOTE_LIFTER_ENCODER_PORTS);

	pid = new PIDController(TOTE_LIFTER_PID_P, TOTE_LIFTER_PID_I,
	TOTE_LIFTER_PID_D, this, this);
	pid->SetOutputRange(-0.8, 1.0);
	pid->SetInputRange(0, TOTE_LIFTER_MAX_DISTANCE);
	pid->SetPercentTolerance(.75);
	encoder->Reset();

	dontUseMagOnPID = true; //topInput->Get() && botInput->Get();
}

ToteLifter::~ToteLifter() {
	delete rightMotor;
	delete leftMotor;
	delete craaawInput;
	delete elevatorInput;
	delete pid;
	delete encoder;
}

void ToteLifter::InitDefaultCommand() {
}

bool ToteLifter::getElevatorInput() {
	return !elevatorInput->Get();
}

bool ToteLifter::getCraaawInput() {
	return !craaawInput->Get();
}

CANTalon *ToteLifter::getLeftMotor() {
	return leftMotor;
}

CANTalon *ToteLifter::getRightMotor() {
	return rightMotor;
}

double ToteLifter::getPosition() {
	return encoder->PIDGet();
}

Encoder *ToteLifter::getEncoder() {
	return encoder;
}

PIDController *ToteLifter::getPID() {
	return pid;
}

void ToteLifter::enablePID(bool enable) {
	if (enable && !pid->IsEnabled()) {
		pid->Enable();
	}
	if (!enable && pid->IsEnabled()) {
		pid->Disable();
	}
}

void ToteLifter::setMotorSpeed(double speed) {
	if (speed < -1) {
		speed = -1;
	} else if (speed > 1) {
		speed = 1;
	}

	enablePID(false);
	leftMotor->Set(speed);
	rightMotor->Set(-speed);
}

void ToteLifter::setSetPoints(double setPoint) {
	pid->SetSetpoint(setPoint);
}

bool ToteLifter::closeEnough(float destination) {
	bool close = encoder->Get() < destination + TOTE_LIFTER_TOLERANCE
			&& encoder->Get() > destination - TOTE_LIFTER_TOLERANCE;
	SmartDashboard::PutBoolean("closeEnough", close);
	return close;
}

void ToteLifter::PIDWrite(float f) {
	if (!dontUseMagOnPID) {
		if (getCraaawInput() && f > 0) {
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

double ToteLifter::PIDGet() {
	return encoder->PIDGet();
}
