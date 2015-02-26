#ifndef AUTO_CAN_GRABERINO_H
#define AUTO_CAN_GRABERINO_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
#include "RobotMap.h"
#include "GyroDriver/IMU.h"

class AutoCanGraberino: public Subsystem
{
private:
	/*AUTO_CAN_MOTOR_TYPE *wench;
	Solenoid *solenoid;
	Encoder *encoder;*/
	DoubleSolenoid *solenoid;
public:
	enum PushState {
		up = true, down = false
	};
	AutoCanGraberino();
	~AutoCanGraberino();
	void Down();
	void Up();
	void InitDefaultCommand();
	DoubleSolenoid::Value getValue();
	/*void setSolenoid();
	void setMotor(float speed);
	Encoder getEnc();*/
};

#endif
