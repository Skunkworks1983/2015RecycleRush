#include <Subsystems/ToteIntakerino.h>
#include "../Commands/ToteHandling/ToteIntake.h"
#include "../RobotMap.h"

ToteIntakerino::ToteIntakerino() :
		Subsystem("ToteIntakerino")
{
	SAFE_INIT(TOTE_INTAKE_SENSOR, isToteSensor = new DigitalInput(TOTE_INTAKE_SENSOR););
	SAFE_INIT(TOTE_INTAKE_MOTOR, toteIntakeMotor = new Talon(TOTE_INTAKE_MOTOR););
}

void ToteIntakerino::InitDefaultCommand()
{
	SetDefaultCommand(new ToteIntake());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

bool ToteIntakerino::hasTote() {
	return isToteSensor->Get();
}

void ToteIntakerino::setMotor(float speed) {
	toteIntakeMotor->Set(speed);
}

void ToteIntakerino::runIfTote() {
	if (this->hasTote()) {
		setMotor(TOTE_INTAKE_MOTOR_FULL);
	} else {
		setMotor(TOTE_INTAKE_MOTOR_NONE);
	}
}
