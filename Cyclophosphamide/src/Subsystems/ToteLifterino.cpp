#include <Subsystems/ToteLifterino.h>
#include "../RobotMap.h"
#include "../Commands/ToteHandling/LiftToHeight.h"
#include "WPILib.h"

ToteLifterino::ToteLifterino() :
		Subsystem("ToteLifterino") {
//	lift_traveled_sensor = new DigitalInput(TOTE_LIFTER_SENSOR);
	SAFE_INIT(TOTE_LIFTER_RIGHT,
			rightMotor = new CANTalon(TOTE_LIFTER_RIGHT););
	SAFE_INIT(TOTE_LIFTER_LEFT, leftMotor = new CANTalon(TOTE_LIFTER_LEFT););
	SAFE_INIT(TOTE_LIFTER_TOTE_INPUT,
			toteUnderInput = new DigitalInput(TOTE_LIFTER_TOTE_INPUT););
	//elevatorTopInput = new DigitalInput(TOTE_LIFTER_ELEVATOR_TOP_INPUT_PORT);
	SmartDashboard::PutNumber("P", TOTE_LIFTER_PID_P);
	SmartDashboard::PutNumber("I", TOTE_LIFTER_PID_I);
	SmartDashboard::PutNumber("D", TOTE_LIFTER_PID_D);
}

void ToteLifterino::InitDefaultCommand() {
	SetDefaultCommand(new LiftToHeight(TOTE_LIFTER_FLOOR));
}

bool ToteLifterino::getElevatorDigitalInput() {
	return elevatorTopInput->Get();
}

CANTalon *ToteLifterino::getLeftMotor() {
	return leftMotor;
}

CANTalon *ToteLifterino::getRightMotor() {
	return rightMotor;
}

bool ToteLifterino::isToteUnder() {
	return toteUnderInput->Get();
}

void ToteLifterino::enablePID(bool enable) {
	if (enable) {
		leftMotor->SetPID(TOTE_LIFTER_PID_P, TOTE_LIFTER_PID_I,
		TOTE_LIFTER_PID_D);
		leftMotor->SetControlMode(CANSpeedController::ControlMode::kPosition);
		leftMotor->SetPosition(0);

		rightMotor->SetControlMode(CANSpeedController::ControlMode::kFollower);
		rightMotor->Set(TOTE_LIFTER_LEFT);

		rightMotor->EnableControl();
		leftMotor->EnableControl();
	} else {
		leftMotor->Disable();
		rightMotor->Disable();
	}
}

//disables the pid
void ToteLifterino::setMotorSpeed(double speed) {
	if (speed < -1) {
		speed = -1;
	} else if (speed > 1) {
		speed = 1;
	}
	enablePID(false);
	leftMotor->Set(speed);
	rightMotor->Set(-speed);
}

void ToteLifterino::setSetPoints(double setPoint) {
	//rightMotor->Set(setPoint * TOTE_LIFTER_TICKS_PER_INCH);
	leftMotor->Set(setPoint * TOTE_LIFTER_TICKS_PER_INCH);
}
