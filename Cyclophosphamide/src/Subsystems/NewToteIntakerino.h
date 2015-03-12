#ifndef CRATE_INTAKERINO_H
#define CRATE_INTAKERINO_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ToteIntakerino: public Subsystem, public PIDOutput, public PIDSource {

	CANTalon *toteIntakeMotor;

	Encoder *encoder;
	PIDController *pid;

	bool hasTote;
	bool isWindingDown;
public:

	NewToteIntakerino();

	void InitDefaultCommand();

	/**
	 * Sets the speed of rollers that pull the tote in
	 * @param speed value to set the motor to
	 */
	void setMotors(float speed);
};

#endif
