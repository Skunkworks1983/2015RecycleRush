#include <CANSpeedController.h>
#include <CANTalon.h>
#include <RobotMap.h>
#include <Subsystems/ToteIntakerino.h>

ToteIntakerino::ToteIntakerino() :
		Subsystem("ToteIntakerino") {
	SAFE_INIT(TOTE_INTAKE_MOTOR_LEFT_PORT,
			toteIntakeMotorLeft = new CANTalon(TOTE_INTAKE_MOTOR_LEFT_PORT););
	SAFE_INIT(TOTE_INTAKE_MOTOR_RIGHT_PORT,
			toteIntakeMotorRight = new CANTalon(TOTE_INTAKE_MOTOR_RIGHT_PORT););
	toteIntakeMotorLeft->SetControlMode(CANSpeedController::kPercentVbus);
	toteIntakeMotorRight->SetControlMode(CANSpeedController::kPercentVbus);
}

void ToteIntakerino::InitDefaultCommand() {
}

void ToteIntakerino::setMotors(float speed){
	toteIntakeMotorLeft->Set(speed);
	toteIntakeMotorRight->Set(-speed);
}
