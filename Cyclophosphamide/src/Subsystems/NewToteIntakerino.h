#ifndef CRATE_INTAKERINO_H
#define CRATE_INTAKERINO_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class NewToteIntakerino: public Subsystem{
private:
	CANTalon *toteIntakeMotorLeft, *toteIntakeMotorRight;
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
