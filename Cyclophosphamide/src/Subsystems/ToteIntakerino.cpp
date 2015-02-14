#include <Subsystems/ToteIntakerino.h>
#include "../Commands/ToteHandling/ToteIntake.h"
#include "../RobotMap.h"

ToteIntakerino::ToteIntakerino() :
		Subsystem("ToteIntakerino")
{
	SAFE_INIT(TOTE_INTAKE_MOTOR, toteIntakeMotor = new CANTalon(TOTE_INTAKE_MOTOR););
	encoder = new Encoder(TOTE_INTAKE_ENCODER_PORT);
	pid = new PIDController(TOTE_INTAKE_P, TOTE_INTAKE_I, TOTE_INTAKE_D, encoder, this);
	pid->SetOutputRange(-1.0, 1.0);
	// todo input range?
	hold();
}

void ToteIntakerino::InitDefaultCommand()
{

}

void ToteIntakerino::PIDWrite(float output) {
	toteIntakeMotor->Set(output);
}

double ToteIntakerino::PIDGet() {
	return encoder->Get();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void ToteIntakerino::hold() {
	toteIntakeMotor->Set(0);
	pid->Enable();
	pid->SetSetpoint(encoder->Get());
}

void ToteIntakerino::setMotor(float speed) {
	pid->Disable();
	toteIntakeMotor->Set(speed);
}

