#include <CANTalon.h>
#include <Commands/ToteIntake/ToteIntake.h>
#include <Encoder.h>
#include <PIDController.h>
#include <RobotMap.h>
#include <Subsystems/ToteIntakerino.h>
#include <chrono>
#include <cmath>

#define TOTE_INTAKE_P 0.5
#define TOTE_INTAKE_I 0.0
#define TOTE_INTAKE_D 0.0

ToteIntakerino::ToteIntakerino() :
		Subsystem("ToteIntakerino") {
	SAFE_INIT(TOTE_INTAKE_MOTOR_PORT_OLD,
			toteIntakeMotor = new CANTalon(TOTE_INTAKE_MOTOR_PORT_OLD););
	encoder = new Encoder(TOTE_INTAKE_ENCODER_PORT);
	encoder->SetDistancePerPulse(1 / TOTE_INTAKE_ENCODER_TICKS_PER_REV);
}

ToteIntakerino::~ToteIntakerino() {
	delete encoder;
	delete toteIntakeMotor;
}

void ToteIntakerino::InitDefaultCommand() {
	//SetDefaultCommand(new ToteIntake(TOTE_INTAKE_RPM));
}

double ToteIntakerino::getRPM() {
	return encoder->GetRate(); /// TOTE_INTAKE_ENCODER_TICKS_PER_REV / 60.0;
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void ToteIntakerino::setMotor(float speed) {
	toteIntakeMotor->Set(speed);
}

Encoder *ToteIntakerino::getEncoder() {
	return encoder;
}
