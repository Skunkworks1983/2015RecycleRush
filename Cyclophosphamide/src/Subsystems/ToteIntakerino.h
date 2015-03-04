#ifndef CRATE_INTAKERINO_H
#define CRATE_INTAKERINO_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 * By Kaeden Wile
 * 
 * Subsystem for loading totes from the human loader station
 */
class ToteIntakerino: public Subsystem, public PIDOutput, public PIDSource {
private:
	/**
	 * Motor that controls the rollers that pull the totes in
	 */
	CANTalon *toteIntakeMotor;

	Encoder *encoder;
	PIDController *pid;

	bool hasTote;
	bool isWindingDown;

	unsigned long startAutoTime;
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

	/**
	 * Stop the motors and keeps them at their current position
	 */
	void hold();

	/**
	 * Tells if a tote is loaded based on the work done by the PID
	 */
	bool isLoaded();

	Encoder *getEncoder();

	virtual void PIDWrite(float f);
	virtual double PIDGet();
	PIDController *getPID();
	unsigned long getTime();
};

#endif
