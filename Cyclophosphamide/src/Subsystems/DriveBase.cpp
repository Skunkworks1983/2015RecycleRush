#include "DriveBase.h"
#include "../RobotMap.h"
#include "../Commands/MecanumDrive.h"
#include <cmath>

DriveBase::DriveBase() :
		PIDSubsystem("DriveBase", DRIVE_P, DRIVE_I, DRIVE_D) {
	motorFrontLeft = new DRIVE_MOTOR_TYPE(DRIVE_MOTOR_FRONT_LEFT);
	motorFrontRight = new DRIVE_MOTOR_TYPE(DRIVE_MOTOR_FRONT_RIGHT);
	motorBackLeft = new DRIVE_MOTOR_TYPE(DRIVE_MOTOR_BACK_LEFT);
	motorBackRight = new DRIVE_MOTOR_TYPE(DRIVE_MOTOR_BACK_RIGHT);

	// Initialize gyro stuff
	serialPort = new SerialPort(57600,SerialPort::kMXP);
	uint8_t update_rate_hz = 50;
	gyro = new IMU(serialPort,update_rate_hz);

	this->SetOutputRange(-180.0, 180.0);
	this->SetInputRange(-180.0, 180.0);
	this->GetPIDController()->SetContinuous(true);
	SetSetpoint(0.0);

	forward = 0.0;
	right = 0.0;
	clockwise = 0.0;
}

DriveBase::~DriveBase() {
	delete motorFrontLeft;
	delete motorFrontRight;
	delete motorBackLeft;
	delete motorBackRight;
}

void DriveBase::InitDefaultCommand() {
	SetDefaultCommand(new MecanumDrive);
}

double DriveBase::ReturnPIDInput() {
	return gyro->GetYaw();
}

void DriveBase::UsePIDOutput(double output) {
	output /= 180.0;
	SmartDashboard::PutNumber("PID output", output);
	setClockwise(output);
}

void DriveBase::setSpeed(double speedFrontLeft, double speedFrontRight,
		double speedBackLeft, double speedBackRight) {
	// Normalize to the max
	double max = fabs(speedFrontLeft);
	if(fabs(speedFrontRight)>max) max = fabs(speedFrontRight);
	if(fabs(speedBackLeft)>max) max = fabs(speedBackLeft);
	if(fabs(speedBackRight)>max) max = fabs(speedBackRight);

	if(max>=1){
		speedFrontLeft /= max;
		speedFrontRight /= max;
		speedBackLeft /= max;
		speedBackRight /= max;
	}

	motorFrontLeft->Set(-speedFrontLeft);
	motorFrontRight->Set(speedFrontRight);
	motorBackLeft->Set(-speedBackLeft);
	motorBackRight->Set(speedBackRight);
}

IMU *DriveBase::getGyro() {
	return gyro;
}

void DriveBase::setTargetAngle(double theta) {
	SetSetpoint(theta);
}

void DriveBase::stopPID() {
	this->Disable();
}

void DriveBase::startPID() {
	this->Enable();
}

double DriveBase::getError() {
	return (gyro->GetYaw()-this->GetSetpoint());
}

void DriveBase::setForward(double f) {
	forward = f;
}

void DriveBase::setRight(double r) {
	right = r;
}

void DriveBase::setClockwise(double c) {
	clockwise = c;
}

void DriveBase::execute() {
	// 'Kinematic transformation'
	double frontLeft = forward + clockwise - right;
	double frontRight = forward - clockwise + right;
	double backLeft = -forward + clockwise + right;
	double backRight = -forward - clockwise - right;

	setSpeed(frontLeft, frontRight, backLeft, backRight);
}
