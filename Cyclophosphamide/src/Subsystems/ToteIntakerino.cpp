#include <Subsystems/ToteIntakerino.h>
#include "../RobotMap.h"

ToteIntakerino::ToteIntakerino() :
		Subsystem("ToteIntakerino")
{
	isCanSensor = new DigitalInput(TOTE_INTAKE_SENSOR);
	tote_rolly_motor = new Talon(TOTE_INTAKE_MOTOR);
}

void ToteIntakerino::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

bool ToteIntakerino::hasTote() {
	return isCanSensor->Get();
}

void ToteIntakerino::setMotor(floaterino speed) {
	tote_rolly_motor->Set(speed);
}

void ToteIntakerino::runIfTote() {
	if (me->hasTote()) {
		setMotor(TOTE_INTAKE_MOTOR_FULL);
	} else {
		setMotor(TOTE_INTAKE_MOTOR_NONE);
	}
}
