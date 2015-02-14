/*
 * DoubleMotorPIDOutput.cpp
 *
 *  Created on: Feb 4, 2015
 *      Author: S-4020395
 */

#include <utilities/DoubleMotorPIDWrapper.h>

DoubleMotorPIDWrapper::DoubleMotorPIDWrapper(double p, double i, double d,
		SpeedController *motor1, SpeedController *motor2, PIDSource *source) {
	motor1pid = new PIDController(p, i, d, source, motor1);
	motor2pid = new PIDController(p, i, d, source, motor2);

}

void DoubleMotorPIDWrapper::setSetpoints(float setPoint) {
	motor1pid->SetSetpoint(setPoint);
	motor2pid->SetSetpoint(setPoint);
}

PIDController *DoubleMotorPIDWrapper::getMotor1() {
	return motor1pid;
}

PIDController *DoubleMotorPIDWrapper::getMotor2() {
	return motor2pid;
}

void DoubleMotorPIDWrapper::enable(bool enable) {
	if (enable) {
		motor1pid->Enable();
		motor2pid->Enable();
	} else {
		motor1pid->Disable();
		motor2pid->Disable();
	}
}

float DoubleMotorPIDWrapper::getError() {
	return motor1pid->GetError();
}

void DoubleMotorPIDWrapper::setPID(double p, double i, double d){
	motor1pid->SetPID(p,i,d);
	motor1pid->SetPID(p,i,d);
}

float DoubleMotorPIDWrapper::getSetPoint(){
	return motor1pid->GetSetpoint();
}
