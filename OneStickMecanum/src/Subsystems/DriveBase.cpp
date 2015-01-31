#include "DriveBase.h"
#include "../RobotMap.h"
#include "../Commands/MecanumDrive.h"
#include <cmath>

DriveBae::DriveBae() :
		PIDSubsystem("DriveBase", 1.0, 0.0, 0.0) {
	motorFrontLeft = new DRIVE_MOTOR_TYPE(DRIVE_MOTOR_FRONT_LEFT);
	motorFrontRight = new DRIVE_MOTOR_TYPE(DRIVE_MOTOR_FRONT_RIGHT);
	motorBackLeft = new DRIVE_MOTOR_TYPE(DRIVE_MOTOR_BACK_LEFT);
	motorBackRight = new DRIVE_MOTOR_TYPE(DRIVE_MOTOR_BACK_RIGHT);

	// Initialize gyro stuff
	serialPort = new SerialPort(57600,SerialPort::kMXP);
	uint8_t update_rate_hz = 50;
	gyro = new IMU(serialPort,update_rate_hz);

	SetSetpoint(gyro->GetYaw());
	this->SetOutputRange(-1, 1);
	this->SetInputRange(-180, 180);
	Enable();
}

DriveBae::~DriveBae() {
	delete motorFrontLeft;
	delete motorFrontRight;
	delete motorBackLeft;
	delete motorBackRight;
}

void DriveBae::InitDefaultCommand() {
	SetDefaultCommand(new MecanumDrive);
}

double DriveBae::ReturnPIDInput() {
	return gyro->GetYaw();
}

void DriveBae::UsePIDOutput(double output) {
	// TODO add correction in translation as well
	if(abs(output) > MECANUM_CORRECTION_THRESHOLD){
		double correction = output*MECANUM_CORRECTION_INTENSITY;
		double frontLeft = motorFrontLeft->Get() + correction;
		double frontRight = motorFrontRight->Get() - correction;
		double backLeft = motorBackLeft->Get() + correction;
		double backRight = motorBackRight->Get() - correction;

		setSpeed(frontLeft, frontRight, backLeft, backRight);
	}
}

void DriveBae::setSpeed(double speedFrontLeft, double speedFrontRight,
		double speedBackLeft, double speedBackRight) {
	// Normalize to the max
	double max = abs(speedFrontLeft);
	if(abs(speedFrontRight)>max) max = abs(speedFrontRight);
	if(abs(speedBackLeft)>max) max = abs(speedBackLeft);
	if(abs(speedBackRight)>max) max = abs(speedBackRight);

	if(max>=1){
		speedFrontLeft /= max;
		speedFrontRight /= max;
		speedBackLeft /= max;
		speedBackRight /= max;
	}

	motorFrontLeft->Set(speedFrontLeft);
	motorFrontRight->Set(-speedFrontRight);
	motorBackLeft->Set(speedBackLeft);
	motorBackRight->Set(-speedBackRight);

	SmartDashboard::PutNumber("Encoder value", motorFrontLeft->GetEncPosition());
}

IMU *DriveBae::getGyro() {
	return gyro;
}

void DriveBae::setTargetAngle(double theta) {
	SetSetpoint(theta);
}

void DriveBae::stopPID() {
	this->Disable();
}

void DriveBae::startPID() {
	this->Enable();
}

double DriveBae::getError() {
	return fmod((gyro->GetYaw()-this->GetSetpoint()), 360.0);
}
