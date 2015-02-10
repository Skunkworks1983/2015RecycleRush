#ifndef DriveBase_H
#define DriveBase_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
#include "RobotMap.h"
#include "GyroDriver/IMU.h"

class DriveBae: public Subsystem, public PIDOutput, public PIDSource {
private:
	PIDController *rotPID;

	DRIVE_MOTOR_TYPE *motorFrontLeft;
	DRIVE_MOTOR_TYPE *motorFrontRight;
	DRIVE_MOTOR_TYPE *motorBackLeft;
	DRIVE_MOTOR_TYPE *motorBackRight;

	IMU *gyro;
	SerialPort *serialPort;
	bool gyroEnabled;

	double forward;
	double right;
	double clockwise;

public:
	DriveBae();
	~DriveBae();

	enum MotorSide {
		FRONT_LEFT, FRONT_RIGHT, BACK_LEFT, BACK_RIGHT
	};

	struct EncoderZero {
		double frontLeft;
		double frontRight;
		double backLeft;
		double backRight;
	};

	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	void setSpeed(double speedFrontLeft, double speedFrontRight,
			double speedBackLeft, double speedBackRight);
	IMU *getGyro();
	void setTargetAngle(double theta);

	void stopPID();
	void startPID();
	double getError();
	double getSetpoint();
	void setSetpoint(float f);
	void setGyroEnabled(bool enable);
	bool isGyroEnabled();

	EncoderZero* getZero();
	void setPIDAll(double P, double I, double D);
	void setAll(double setPoint);
	void enablePIDAll(bool state);
	void setModeAll(CANTalon::ControlMode mode);
	void zeroEncoders();
	bool withinThreshhold(double driveThreshhold, double targetDistance, EncoderZero* billy);

	void setForward(double f);
	void setRight(double r);
	void setClockwise(double c);
	double getClockwise();
	void execute();
	virtual void PIDWrite(float f);
	virtual double PIDGet();

	DRIVE_MOTOR_TYPE *getMotor(MotorSide side);
};

#endif
