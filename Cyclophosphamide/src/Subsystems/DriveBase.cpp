#include <CANTalon.h>
#include <Commands/Drivebase/MecanumDrive.h>
#include <PIDController.h>
#include <SerialPort.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Subsystems/DriveBase.h>
#include <cmath>
#include <cstdint>

DriveBase::DriveBase() :
		Subsystem("DriveBae") {
	SAFE_INIT(DRIVE_MOTOR_FRONT_LEFT_PORT,
			motorFrontLeft = new DRIVE_MOTOR_TYPE(DRIVE_MOTOR_FRONT_LEFT_PORT););
	SAFE_INIT(DRIVE_MOTOR_FRONT_RIGHT_PORT,
			motorFrontRight = new DRIVE_MOTOR_TYPE(DRIVE_MOTOR_FRONT_RIGHT_PORT););
	SAFE_INIT(DRIVE_MOTOR_BACK_LEFT_PORT,
			motorBackLeft = new DRIVE_MOTOR_TYPE(DRIVE_MOTOR_BACK_LEFT_PORT););
	SAFE_INIT(DRIVE_MOTOR_BACK_RIGHT_PORT,
			motorBackRight = new DRIVE_MOTOR_TYPE(DRIVE_MOTOR_BACK_RIGHT_PORT););
	motorFrontLeft->ConfigEncoderCodesPerRev(ENCODER_TICKS_PER_REV);
	motorFrontRight->ConfigEncoderCodesPerRev(ENCODER_TICKS_PER_REV);
	motorBackLeft->ConfigEncoderCodesPerRev(ENCODER_TICKS_PER_REV);
	motorBackRight->ConfigEncoderCodesPerRev(ENCODER_TICKS_PER_REV);
	enablePIDAll(true);
	//setModeAll(CANSpeedController::kPosition);

	// Initialize gyro stuff
	serialPort = new SerialPort(57600, SerialPort::kMXP);
	uint8_t update_rate_hz = 50;
	gyro = new IMU(serialPort, update_rate_hz);
	gyroEnabled = true; //gyro != NULL;

	rotPID = new PIDController(DRIVE_ROT_P, DRIVE_ROT_I, DRIVE_ROT_D, gyro,
			this);
	rotPID->Disable();

	rotPID->SetOutputRange(-180.0, 180.0);
	rotPID->SetInputRange(-180.0, 180.0);
	rotPID->SetContinuous(true);
	rotPID->SetSetpoint(gyro->GetYaw());

	lightSensor = new DigitalInput(DOESNT_EXIST);

//	strafePID = new PIDController(DRIVE_STRAFE_P, DRIVE_STRAFE_I,
//	DRIVE_STRAFE_D, &VisionRunner::getInstance(), new StrafePIDOutput(this));

//	strafePID->SetOutputRange(-1, 1);

	forward = 0.0;
	right = 0.0;
	clockwise = 0.0;

	accel = new BuiltInAccelerometer();
}

DriveBase::~DriveBase() {
	delete motorFrontLeft;
	delete motorFrontRight;
	delete motorBackLeft;
	delete motorBackRight;
	delete rotPID;
	delete serialPort;
	delete gyro;
	delete strafePID;
	delete lightSensor;
}

void DriveBase::InitDefaultCommand() {
	SetDefaultCommand(new MecanumDrive());
}

void DriveBase::setStrafeSetPoint(double setPoint) {
	strafePID->SetSetpoint(setPoint);
}

void DriveBase::enableStrafePID(bool state) {
	if (state) {
		strafePID->Enable();
	} else {
		strafePID->Disable();
	}
}

Accelerometer *DriveBase::getBuiltInAccel() {
	return accel;
}

void DriveBase::setSpeed(double speedFrontLeft, double speedFrontRight,
		double speedBackLeft, double speedBackRight) {
	// Normalize to the max
	double max = fabs(speedFrontLeft);
	if (fabs(speedFrontRight) > max) {
		max = fabs(speedFrontRight);
	}
	if (fabs(speedBackLeft) > max) {
		max = fabs(speedBackLeft);
	}
	if (fabs(speedBackRight) > max) {
		max = fabs(speedBackRight);
	}

	if (max >= 1) {
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

double DriveBase::getForward() {
	return forward;
}

double DriveBase::getRight() {
	return right;
}

IMU *DriveBase::getGyro() {
	return gyro;
}

void DriveBase::setGyroEnabled(bool enable) {
	gyroEnabled = enable;
}

bool DriveBase::isGyroEnabled() {
	return gyroEnabled;
}

void DriveBase::setPIDAll(double P, double I, double D) {
	motorFrontLeft->SetPID(P, I, D);
	motorFrontRight->SetPID(P, I, D);
	motorBackLeft->SetPID(P, I, D);
	motorBackRight->SetPID(P, I, D);
}

void DriveBase::setAll(double setPoint) {
	motorFrontLeft->Set(-setPoint);
	motorFrontRight->Set(setPoint);
	motorBackLeft->Set(-setPoint);
	motorBackRight->Set(setPoint);
}

void DriveBase::setModeAll(CANSpeedController::ControlMode mode) {
	motorFrontLeft->SetControlMode(mode);
	motorFrontRight->SetControlMode(mode);
	motorBackLeft->SetControlMode(mode);
	motorBackRight->SetControlMode(mode);
}

void DriveBase::zeroEncoders() {
	motorFrontLeft->SetPosition(0);
	motorFrontRight->SetPosition(0);
	motorBackLeft->SetPosition(0);
	motorBackRight->SetPosition(0);
}

bool DriveBase::withinThreshhold(double driveThreshhold, double targetDistance) {
	SmartDashboard::PutNumber("backLeft",
			fabs(motorBackLeft->GetEncPosition()) - targetDistance);
	SmartDashboard::PutNumber("frontLeft",
			fabs(motorBackLeft->GetEncPosition()) - targetDistance);
	SmartDashboard::PutNumber("backRight",
			fabs(motorFrontRight->GetEncPosition()) - targetDistance);
	SmartDashboard::PutNumber("frontRight",
			fabs(motorBackRight->GetEncPosition()) - targetDistance);

	if (fabs(motorBackLeft->GetEncPosition()) - targetDistance < driveThreshhold
			&& fabs(motorFrontLeft->GetEncPosition()) - targetDistance
					< driveThreshhold
			&& fabs(motorFrontRight->GetEncPosition()) - targetDistance
					< driveThreshhold
			&& fabs(motorBackRight->GetEncPosition()) - targetDistance
					< driveThreshhold) {
		SmartDashboard::PutBoolean("WithinThreshold", true);
		return true;
	}
	SmartDashboard::PutBoolean("WithinThreshold", true);
	return false;
}

void DriveBase::enablePIDAll(bool state) {
	if (state) {
		motorFrontLeft->EnableControl();
		motorFrontRight->EnableControl();
		motorBackLeft->EnableControl();
		motorBackRight->EnableControl();
	} else {
		/*motorFrontLeft->Disable();
		motorFrontRight->Disable();
		motorBackLeft->Disable();
		motorBackRight->Disable();*/
	}
}

void DriveBase::setTargetAngle(double theta) {
	rotPID->SetSetpoint(theta);
}

void DriveBase::stopRotPID() {
	rotPID->Disable();
}

void DriveBase::startRotPID() {
	if (gyroEnabled) {
		rotPID->Enable();
	}
}

double DriveBase::getError() {
	return (gyro->GetYaw() - rotPID->GetSetpoint());
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

double DriveBase::getClockwise() {
	return clockwise;
}

void DriveBase::execute() {
// 'Kinematic transformation'
	double frontLeft = forward + clockwise - right;
	double frontRight = forward - clockwise - right;
	double backLeft = forward + (clockwise) + (right);
	double backRight = forward - (clockwise) + (right);

	setSpeed(frontLeft, frontRight, backLeft, backRight);
}

void DriveBase::PIDWrite(float output) {
	output /= 180.0;
	setClockwise(-output);
}

double DriveBase::PIDGet() {
	return gyro->GetYaw();
}

double DriveBase::getSetpoint() {
	return rotPID->GetSetpoint();
}

void DriveBase::setSetpoint(float f) {
	rotPID->SetSetpoint(f);
}

void DriveBase::zeroPIDOutput() {
	rotPID->SetSetpoint(gyro->GetYaw());
}

DRIVE_MOTOR_TYPE *DriveBase::getMotor(MotorSide side) {
	switch (side) {
	case MotorSide::FRONT_LEFT:
		return motorFrontLeft;
	case MotorSide::FRONT_RIGHT:
		return motorFrontRight;
	case MotorSide::BACK_LEFT:
		return motorBackLeft;
	case MotorSide::BACK_RIGHT:
		return motorBackRight;
	}
}

bool DriveBase::getLightSensor() {
	return lightSensor->Get();
}
