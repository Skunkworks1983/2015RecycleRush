#include <CANTalon.h>
#include <Commands/ToteIntake/ToteIntake.h>
#include <Encoder.h>
#include <PIDController.h>
#include <RobotMap.h>
#include <Subsystems/ToteIntakerino.h>
#include <chrono>
#include <cmath>

ToteIntakerino::ToteIntakerino() :
		Subsystem("ToteIntakerino") {
	SAFE_INIT(TOTE_INTAKE_MOTOR_PORT_OLD,
			toteIntakeMotor = new CANTalon(TOTE_INTAKE_MOTOR_PORT_OLD););
	encoder = new Encoder(TOTE_INTAKE_ENCODER_PORT);
	pid = new PIDController(TOTE_INTAKE_P, TOTE_INTAKE_I, TOTE_INTAKE_D,
			encoder, this);
	pid->SetOutputRange(-TOTE_INTAKE_PID_FULL, TOTE_INTAKE_PID_FULL);
	//pid->Enable();
	hasTote = false;
	isWindingDown = false;
	startAutoTime = getTime();
}

void ToteIntakerino::InitDefaultCommand() {
	SetDefaultCommand(new ToteIntake(TOTE_INTAKE_MOTOR_SLOW));
}

void ToteIntakerino::PIDWrite(float output) {
	/*
	SmartDashboard::PutNumber("intake PID output", output);
	if(isWindingDown && fabs(output) < TOTE_INTAKE_DETECTION_THRESHOLD){
		isWindingDown = false;
	} else if (fabs(output) > TOTE_INTAKE_DETECTION_THRESHOLD) {
		hasTote = true;
		startAutoTime = getTime();
	}
	if(hasTote){
		toteIntakeMotor->Set(TOTE_INTAKE_MOTOR_FULL);
		if(getTime() > startAutoTime + TOTE_INTAKE_AUTO_TIME_MS){
			hasTote = false;
			hold();
		}
		// if timed out hasTote = false
	} else {
		if (output < 0) {
			output = 0;
		}
		toteIntakeMotor->Set(-output);
	}
	*/

	if (output < 0) {
		output = 0;
	}
	toteIntakeMotor->Set(-output);
}

double ToteIntakerino::PIDGet() {
	return encoder->Get() * TOTE_INTAKE_ENCODER_TICKS_PER_REV;
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void ToteIntakerino::hold() {
	encoder->Reset();
	pid->SetSetpoint(0);
	pid->Enable();
}

void ToteIntakerino::setMotor(float speed) {
	pid->Disable();
	toteIntakeMotor->Set(speed);
	if (fabs(speed) > 0) {
		hasTote = false;
		isWindingDown = true;
	}
}

Encoder *ToteIntakerino::getEncoder() {
	return encoder;
}

bool ToteIntakerino::isLoaded() {
	return hasTote;
}

PIDController *ToteIntakerino::getPID() {
	return pid;
}

unsigned long ToteIntakerino::getTime() {
	using namespace std::chrono;
	unsigned long ms = duration_cast<milliseconds>(
			high_resolution_clock::now().time_since_epoch()).count();
	return ms;
}
