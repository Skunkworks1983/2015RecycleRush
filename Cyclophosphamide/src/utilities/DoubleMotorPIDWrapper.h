/*
 * DoubleMotorPIDOutput.h
 *
 *  Created on: Feb 4, 2015
 *      Author: S-4020395
 */

#ifndef SRC_UTILITIES_DOUBLEMOTORPIDOUTPUT_H_
#define SRC_UTILITIES_DOUBLEMOTORPIDOUTPUT_H_

#include "WPILib.h"

class DoubleMotorPIDWrapper {
private:
	SpeedController *motor1, *motor2;
	PIDController *motor1pid, *motor2pid;
	PIDSource *source;
public:
	DoubleMotorPIDWrapper(double p, double i, double d, SpeedController *motor1,
			SpeedController *motor2, PIDSource *source);
	void setSetpoints(float setPoint);
	void enable(bool enable);
	PIDController *getMotor1();
	PIDController *getMotor2();
	float getError();
	void setPID(double p, double i, double d);
	void setP(double p);
	void setI(double i);
	void setD(double d);

	double getP(){return motor1pid->GetP();}
	double getI(){return motor1pid->GetI();}
	double getD(){return motor1pid->GetD();}

	float getSetPoint();

};

#endif /* SRC_UTILITIES_DOUBLEMOTORPIDOUTPUT_H_ */
