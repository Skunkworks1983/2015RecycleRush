#ifndef ToteLifterino_H
#define ToteLifterino_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "robotmap.h"
#include "../utilities/DoubleMotorPIDWrapper.h"

class ToteLifterino: public Subsystem, public PIDOutput, public PIDSource {
private:
	DigitalInput *topInput, *botInput;
	CANTalon *rightMotor, *leftMotor;
	PIDController *pid;
	Encoder *encoder;
	bool coopState, ignoreInput, notZeroed;
public:
	ToteLifterino();
	void InitDefaultCommand();
	void WatchDogg();
	bool getMagInput();
	bool getBotInput();
	void setZeroed(bool zeroed);
	bool isCoop();
	void setCoop(bool isCoop);
	bool lowerThan(double height);
	CANTalon *getLeftMotor();
	CANTalon *getRightMotor();
	float getPosition();
	Encoder *getEncoder();
	PIDController *getPID();
	bool closeEnough(float destination);
	void setMotorSpeed(double speed);
	void setSetPoints(double setPoint);
	void enablePID(bool enable);
	virtual void PIDWrite(float f);
	virtual double PIDGet();
	bool getMagSensor();
};

#endif
