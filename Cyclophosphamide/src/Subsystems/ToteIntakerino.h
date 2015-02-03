#ifndef CRATE_INTAKERINO_H
#define CRATE_INTAKERINO_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 * By Kaeden Wile
 * 
 * Subsystem for loading totes from the human loader station
 */
class ToteIntakerino: public Subsystem
{
private:
	/**
	 * Sensor of whether or not the subsystem contains a tote or not.
	 */
	DigitalInput *isCanSensor;
	/**
	 * Motor that controls the rollers that pull the totes in
	 */
	Talon *tote_rolly_motor;
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
	 * Checks if there is a tote in the subsystem currently
	 * @return if there is a tote
	 */
	bool hasTote();
	
	/**
	 * Sets the speed of rollers that pull the tote in
	 * @param speed value to set the motor to
	 */
	void setMotor(float speed);
	
	/**
	 * Function called by the Command that calls setMotor if hasTote evaluates to true
	 */
	void runIfTote();
};

#endif
