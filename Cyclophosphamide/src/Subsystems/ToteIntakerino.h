#ifndef CRATE_INTAKERINO_H
#define CRATE_INTAKERINO_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
/*!
 * Subsystem for loading totes from the human loader station
 * encoders runs off/on
 * PID setpoint 0 (ground level)
 */
class ToteIntakerino: public Subsystem, public PIDOutput, public PIDSource {
private:
	/*
	 * Motor that controls the rollers that pull the totes in
	 */
	CANTalon *toteIntakeMotor;

	Encoder *encoder;
	PIDController *pid;

	bool hasTote;
	bool isWindingDown;
public:

	ToteIntakerino();

	void InitDefaultCommand();

	/**
	 * Sets the speed of rollers that pull the tote in
	 * @param speed value to set the motor to
	 */
	void setMotors(float speed);
};

#endif
