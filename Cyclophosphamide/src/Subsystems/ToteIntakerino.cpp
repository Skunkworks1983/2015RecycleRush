#include <Subsystems/ToteIntakerino.h>
#include "../Commands/ToteHandling/ToteIntake.h"
#include "../RobotMap.h"
#include <cmath>

ToteIntakerino::ToteIntakerino() :
		Subsystem("ToteIntakerino") {
	SAFE_INIT(TOTE_INTAKE_MOTOR_PORT,
			toteIntakeMotor = new CANTalon(TOTE_INTAKE_MOTOR_PORT););
	encoder = new Encoder(TOTE_INTAKE_ENCODER_PORT);
	pid = new PIDController(TOTE_INTAKE_P, TOTE_INTAKE_I, TOTE_INTAKE_D,
			encoder, this);
	pid->SetOutputRange(-TOTE_INTAKE_PID_FULL, TOTE_INTAKE_PID_FULL);
	pid->Enable();
	hasTote = false;
	isWindingDown = false;
	hold();
}

void ToteIntakerino::InitDefaultCommand() {
	//SetDefaultCommand(new ToteIntake(ToteIntake::stopped));
}

void ToteIntakerino::PIDWrite(float output) {

	if (output < 0) {
		output = 0;
	}
	toteIntakeMotor->Set(-output);
	if (abs(output) > TOTE_INTAKE_DETECTION_THRESHOLD /* && !isWindingDown*/) {
		hasTote = true;
	} else {
		isWindingDown = false;
	}
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

	setMotor(0);
}

void ToteIntakerino::setMotor(float speed) {
	pid->Disable();
	toteIntakeMotor->Set(speed);
	if (abs(speed) > 0) {
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

