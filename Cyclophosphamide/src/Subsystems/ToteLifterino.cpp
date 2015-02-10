#include <Subsystems/ToteLifterino.h>
#include "../RobotMap.h"

ToteLifterino::ToteLifterino() :
		Subsystem("ToteLifterino") {
//	lift_traveled_sensor = new DigitalInput(TOTE_LIFTER_SENSOR);
	SAFE_INIT(TOTE_LIFTER_RIGHT, rightMotor = new CANTalon(TOTE_LIFTER_RIGHT););
	SAFE_INIT(TOTE_LIFTER_LEFT, leftMotor = new CANTalon(TOTE_LIFTER_LEFT););
	SAFE_INIT(TOTE_LIFTER_TOTE_INPUT,
			toteUnderInput = new DigitalInput(TOTE_LIFTER_TOTE_INPUT););
#if TOTE_LIFTER_USING_PID
	leftMotor->SetPID(TOTE_LIFTER_PID_P, TOTE_LIFTER_PID_I, TOTE_LIFTER_PID_D);
	//rightMotor->SetPID(TOTE_LIFTER_PID_P, TOTE_LIFTER_PID_I, TOTE_LIFTER_PID_D);
#endif
	leftMotor->SetControlMode(CANSpeedController::ControlMode::kPosition);
	leftMotor->SetPosition(0);
}

void ToteLifterino::InitDefaultCommand() {
}

CANTalon *ToteLifterino::getLeftMotor() {
	return leftMotor;
}

CANTalon *ToteLifterino::getRightMotor() {
	return rightMotor;
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
	if (speed == 0) {
		leftMotor->StopMotor();
		//rightMotor->StopMotor();
	} else {
		leftMotor->Set(speed);
		//rightMotor->Set(-speed);	//maybe doesnt need to be negative?
	}
}

#if TOTE_LIFTER_USING_PID
void ToteLifterino::enablePID(bool enable) {
	if (enable) {
		leftMotor->EnableControl();
		//rightMotor->EnableControl();
	} else {
		leftMotor->Disable();
		//rightMotor->Disable();
	}
}

void ToteLifterino::setSetPoints(double setPoint) {
	//rightMotor->SetPosition(leftMotor->GetEncPosition() + setPoint * TOTE_LIFTER_TICKS_PER_INCH);

	leftMotor->Set(setPoint * TOTE_LIFTER_TICKS_PER_INCH);
}
#endif
