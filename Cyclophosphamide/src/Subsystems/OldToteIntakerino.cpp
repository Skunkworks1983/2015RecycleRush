#include <CANTalon.h>
#include <Commands/ToteIntake/OldToteIntake.h>
#include <Encoder.h>
#include <PIDController.h>
#include <RobotMap.h>
#include <Subsystems/OldToteIntakerino.h>
#include <chrono>
#include <cmath>

// TODO tune these
// TODO move these to RobotMap.h
#define TOTE_INTAKE_RPM 10
#define TOTE_INTAKE_P 0.005
#define TOTE_INTAKE_I 0.0
#define TOTE_INTAKE_D 0.0

OldToteIntakerino::OldToteIntakerino() :
		Subsystem("OldToteIntakerino") {
	SAFE_INIT(TOTE_INTAKE_MOTOR_PORT_OLD,
			toteIntakeMotor = new CANTalon(TOTE_INTAKE_MOTOR_PORT_OLD););
	encoder = new Encoder(TOTE_INTAKE_ENCODER_PORT);
	pid = new PIDController(TOTE_INTAKE_P, TOTE_INTAKE_I, TOTE_INTAKE_D,
			encoder, this);
	pid->SetOutputRange(-TOTE_INTAKE_PID_FULL, TOTE_INTAKE_PID_FULL);
	pid->Enable();
}

void OldToteIntakerino::InitDefaultCommand() {
	SetDefaultCommand(new OldToteIntake(TOTE_INTAKE_MOTOR_SLOW));
}

void OldToteIntakerino::PIDWrite(float output) {
	toteIntakeMotor->Set(output);
}

double OldToteIntakerino::PIDGet() {
	return getRPM();
}

double OldToteIntakerino::getRPM() {
	return encoder->Get() / TOTE_INTAKE_ENCODER_TICKS_PER_REV * 60.0;
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void OldToteIntakerino::setMotor(float speed) {
	pid->SetSetpoint(speed);
}

Encoder *OldToteIntakerino::getEncoder() {
	return encoder;
}

PIDController *OldToteIntakerino::getPID() {
	return pid;
}
