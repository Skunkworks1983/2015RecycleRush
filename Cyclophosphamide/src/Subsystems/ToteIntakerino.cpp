#include <CANTalon.h>
#include <Commands/ToteIntake/ToteIntake.h>
#include <Encoder.h>
#include <PIDController.h>
#include <RobotMap.h>
#include <Subsystems/ToteIntakerino.h>
#include <chrono>
#include <cmath>

// TODO tune these
// TODO move these to RobotMap.h
#define TOTE_INTAKE_RPM 4.0
#define TOTE_INTAKE_P 0.1
#define TOTE_INTAKE_I 0.0
#define TOTE_INTAKE_D 0.0

ToteIntakerino::ToteIntakerino() :
		Subsystem("ToteIntakerino") {
	SAFE_INIT(TOTE_INTAKE_MOTOR_PORT_OLD,
			toteIntakeMotor = new CANTalon(TOTE_INTAKE_MOTOR_PORT_OLD););
	encoder = new Encoder(TOTE_INTAKE_ENCODER_PORT);
	pid = new PIDController(TOTE_INTAKE_P, TOTE_INTAKE_I, TOTE_INTAKE_D,
			encoder, this);
	pid->SetOutputRange(-TOTE_INTAKE_PID_FULL, TOTE_INTAKE_PID_FULL);
	pid->Enable();
}

ToteIntakerino::~ToteIntakerino(){
	delete encoder;
	delete pid;
	delete toteIntakeMotor;
}


void ToteIntakerino::InitDefaultCommand() {
	SetDefaultCommand(new ToteIntake(TOTE_INTAKE_RPM));
}

void ToteIntakerino::PIDWrite(float output) {
	//SmartDashboard::PutNumber("intake output", output);
	toteIntakeMotor->Set(output);
}

double ToteIntakerino::PIDGet() {
	return getRPM();
}

double ToteIntakerino::getRPM() {
	return encoder->GetRate() / TOTE_INTAKE_ENCODER_TICKS_PER_REV / 60.0;
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void ToteIntakerino::setMotor(float speed) {
	pid->SetSetpoint(speed);
}

Encoder *ToteIntakerino::getEncoder() {
	return encoder;
}

PIDController *ToteIntakerino::getPID() {
	return pid;
}
