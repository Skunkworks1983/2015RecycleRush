#include <Subsystems/ToteIntakerino.h>
#include "../Commands/ToteHandling/ToteIntake.h"
#include "../RobotMap.h"

ToteIntakerino::ToteIntakerino() :
		Subsystem("ToteIntakerino")
{
	SAFE_INIT(TOTE_INTAKE_SENSOR, isToteSensor = new DigitalInput(TOTE_INTAKE_SENSOR););
	SAFE_INIT(TOTE_INTAKE_MOTOR, toteIntakeMotor = new CANTalon(TOTE_INTAKE_MOTOR););
	toteIntakeMotor->SetPID(TOTE_INTAKE_P, TOTE_INTAKE_I, TOTE_INTAKE_D);
	toteIntakeMotor->EnableControl();
}

void ToteIntakerino::InitDefaultCommand()
{

}

// Put methods for controlling this subsystem
// here. Call these from Commands.

bool ToteIntakerino::hasTote() {
	return isToteSensor->Get();
}

void ToteIntakerino::hold() {
	toteIntakeMotor->SetControlMode(CANSpeedController::ControlMode::kPosition);
	toteIntakeMotor->SetPosition(0);
	toteIntakeMotor->Set(0);
}

void ToteIntakerino::setMotor(float speed) {
	toteIntakeMotor->SetControlMode(CANSpeedController::ControlMode::kPercentVbus);
	toteIntakeMotor->Set(speed);
}

void ToteIntakerino::runIfTote() {
	if (this->hasTote()) {
		setMotor(TOTE_INTAKE_MOTOR_FULL);
	} else {
		setMotor(TOTE_INTAKE_MOTOR_NONE);
	}
}
