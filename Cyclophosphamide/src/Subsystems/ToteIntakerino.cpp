#include <Subsystems/ToteIntakerino.h>
#include "../RobotMap.h"

ToteIntakerino::ToteIntakerino() :
		Subsystem("ToteIntakerino")
{
	SAFE_INIT(TOTE_INTAKE_SENSOR, isCanSensor = new DigitalInput(TOTE_INTAKE_SENSOR););
	SAFE_INIT(TOTE_INTAKE_MOTOR, tote_rolly_motor = new Talon(TOTE_INTAKE_MOTOR););
}

void ToteIntakerino::InitDefaultCommand()
{
//	SetDefaultCommand(new ToteIntake());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

bool ToteIntakerino::hasTote() {
	return isCanSensor->Get();
}

void ToteIntakerino::setMotor(float speed) {
	tote_rolly_motor->Set(speed);
}

void ToteIntakerino::runIfTote() {
	if (me->hasTote()) {
		setMotor(TOTE_INTAKE_MOTOR_FULL);
	} else {
		setMotor(TOTE_INTAKE_MOTOR_NONE);
	}
}
