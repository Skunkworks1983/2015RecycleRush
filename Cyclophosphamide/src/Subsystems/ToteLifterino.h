#ifndef ToteLifterino_H
#define ToteLifterino_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "robotmap.h"
#include "../utilities/DoubleMotorPIDWrapper.h"

class ToteLifterino: public Subsystem, public PIDOutput, public PIDSource {
private:
	DigitalInput *elevatorInput, *craaawInput;
	CANTalon *rightMotor, *leftMotor;
	PIDController *pid;
	Encoder *encoder;
	bool ignoreInput, zeroed;
public:
	ToteLifterino();
	void InitDefaultCommand();
	bool getElevatorInput();
	bool getCraaawInput();
	void setZeroed(bool zeroed);
	bool lowerThan(double height);
	CANTalon *getLeftMotor();
	CANTalon *getRightMotor();
	double getPosition();
	Encoder *getEncoder();
	PIDController *getPID();
	bool closeEnough(float destination);
	void setMotorSpeed(double speed);
	void setSetPoints(double setPoint);
	void enablePID(bool enable);
	virtual void PIDWrite(float f);
	virtual double PIDGet();
};

#endif
