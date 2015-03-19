#ifndef TOTE_INTAKERINO_H
#define TOTE_INTAKERINO_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 * By Kaeden Wile
 *
 * Subsystem for loading totes from the human loader station
 */
class ToteIntakerino: public Subsystem, public PIDOutput, public PIDSource {
private:
	// RIP in peace Kaeden's documentation
	/**
	 * Motor that controls the rollers that pull the totes in
	 */
	CANTalon *toteIntakeMotor;

	Encoder *encoder;
	PIDController *pid;
public:
	/**
	 * Default constructor
	 */
	ToteIntakerino();
	/**
	 * Does nothing because call creates circular dependencies and compile errors
	 */
	void InitDefaultCommand();

	/**
	 * Sets the speed of rollers that pull the tote in
	 * @param speed value to set the motor to
	 */
	void setMotor(float speed);

	double getRPM();

	Encoder *getEncoder();

	virtual void PIDWrite(float f);
	virtual double PIDGet();
	PIDController *getPID();
};

#endif
