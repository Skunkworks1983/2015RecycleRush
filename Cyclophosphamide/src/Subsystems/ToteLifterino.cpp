#include <Subsystems/ToteLifterino.h>
#include "../RobotMap.h"

ToteLifterino::ToteLifterino() :
		Subsystem("ToteLifterino") {
//	lift_traveled_sensor = new DigitalInput(TOTE_LIFTER_SENSOR);
	SAFE_INIT(TOTE_LIFTER_RIGHT, rightMotor = new Talon(TOTE_LIFTER_RIGHT););
	SAFE_INIT(TOTE_LIFTER_LEFT, leftMotor = new Talon(TOTE_LIFTER_LEFT););
	SAFE_INIT(TOTE_LIFTER_ENCODER_CA,
			encoder = new Encoder(TOTE_LIFTER_ENCODER_CA, TOTE_LIFTER_ENCODER_CB, TOTE_LIFTER_ENCODER_REVERSED););
	SAFE_INIT(TOTE_LIFTER_TOTE_INPUT,
			toteUnderInput = new DigitalInput(TOTE_LIFTER_TOTE_INPUT););
	encoder->Reset();

	pidOutput = new DoubleMotorPIDOutput(leftMotor, rightMotor);

	pid = new PIDController(TOTE_LIFTER_PID_P, TOTE_LIFTER_PID_I,
	TOTE_LIFTER_PID_D, encoder, pidOutput);
}

void ToteLifterino::InitDefaultCommand() {

}

Encoder *ToteLifterino::getEncoder() {
	return encoder;
}

bool ToteLifterino::closeEnough(int destination) {
	//broken
	//return (encoder->GetDistance() >= destination - TOTE_LIFTER_ENCODER_DEADBAND);
	return false;
}

bool ToteLifterino::isToteUnder() {
	return toteUnderInput->Get();
}

void ToteLifterino::setMotors(double speed) {
	leftMotor->Set(speed);
	rightMotor->Set(-speed);	//maybe doesnt need to be negative?
}

#if TOTE_LIFTER_USING_PID
void ToteLifterino::enablePID(bool enable) {
	if (enable) {
		pid->Enable();
	} else {
		pid->Disable();
	}
}

void ToteLifterino::setSetPoints(double setPoint) {
	pid->SetSetpoint(setPoint / TOTE_LIFTER_TICKS_PER_INCH);
}
#endif
