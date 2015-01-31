#include "DriveBase.h"
#include "../RobotMap.h"
#include "../Commands/MecanumDrive.h"
#include <cmath>

DriveBae::DriveBae() :
		Subsystem("DriveBase") {
	motorFrontLeft = new DRIVE_MOTOR_TYPE(DRIVE_MOTOR_FRONT_LEFT);
	motorFrontRight = new DRIVE_MOTOR_TYPE(DRIVE_MOTOR_FRONT_RIGHT);
	motorBackLeft = new DRIVE_MOTOR_TYPE(DRIVE_MOTOR_BACK_LEFT);
	motorBackRight = new DRIVE_MOTOR_TYPE(DRIVE_MOTOR_BACK_RIGHT);
	rotPID = new PIDController(DRIVE_ROT_P , DRIVE_ROT_I, DRIVE_ROT_D, gyro, this);

	// Initialize gyro stuff
	serialPort = new SerialPort(57600,SerialPort::kMXP);
	uint8_t update_rate_hz = 50;
	gyro = new IMU(serialPort,update_rate_hz);

	rotPID->SetOutputRange(-180.0, 180.0);
	rotPID->SetInputRange(-180.0, 180.0);
	rotPID->SetContinuous(true);
	rotPID->SetSetpoint(0.0);

	forward = 0.0;
	right = 0.0;
	clockwise = 0.0;
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

void DriveBae::setSpeed(double speedFrontLeft, double speedFrontRight,
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

IMU *DriveBae::getGyro() {
	return gyro;
}

void DriveBae::setTargetAngle(double theta) {
	rotPID->SetSetpoint(theta);
}

void DriveBae::stopPID() {
	rotPID->Disable();
}

void DriveBae::startPID() {
	rotPID->Enable();
}

double DriveBae::getError() {
	return (gyro->GetYaw()-rotPID->GetSetpoint());
}

void DriveBae::setForward(double f) {
	forward = f;
}

void DriveBae::setRight(double r) {
	right = r;
}

void DriveBae::setClockwise(double c) {
	clockwise = c;
}

double DriveBae::getClockwise() {
	return clockwise;
}

void DriveBae::execute() {
	// 'Kinematic transformation'
	double frontLeft = forward + clockwise - right;
	double frontRight = forward - clockwise + right;
	double backLeft = forward + clockwise + right;
	double backRight = forward - clockwise - right;

	setSpeed(frontLeft, frontRight, backLeft, backRight);
}
void DriveBae::PIDWrite(float output){
	output /= 180.0;
	SmartDashboard::PutNumber("PID output", output);
	setClockwise(output);
}

double DriveBae::PIDGet(){
	return gyro->GetYaw();
}

double DriveBae::getSetpoint() {
	return rotPID->GetSetpoint();
}

void DriveBae::setSetpoint(float f) {
	rotPID->SetSetpoint(f);
}

DRIVE_MOTOR_TYPE *DriveBae::getSpecialMotor(){
	return motorFrontLeft;
}
