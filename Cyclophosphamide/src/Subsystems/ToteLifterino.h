#ifndef ToteLifterino_H
#define ToteLifterino_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "robotmap.h"
#include "../utilities/DoubleMotorPIDOutput.h"

class ToteLifterino: public Subsystem {
private:
	Encoder *encoder;
	DigitalInput *toteUnderInput;
	Talon *rightMotor,*leftMotor;
	PIDController *pid;
	DoubleMotorPIDOutput *pidOutput;
public:
	/**
	 * Default Constructor. Normal Initialization
	 */
	ToteLifterino();
	/**
	 * Does nothing because SetDefaultCommand call creates circular includes and compile errors
	 */
	void InitDefaultCommand();

	/**
	 * Returns the encoder
	 *
	 * @Ross
	 */
	Encoder *getEncoder();

	bool isToteUnder();
	/**
	 * Used to check if the stacker is close enough to its encoder value for each position.
	 * Allowed variablitity determined by TOTE_LIFTER_ENCODER_DEADBAND.
	 * Takes a constant and checks if (value > constant - deadband && value < constant + deadband)
	 * @return if the value is close enough to the constant
	 */
	bool closeEnough(int destination);

	void setMotors(double speed);

#if TOTE_LIFTER_USING_PID
	void setSetPoints(double setPoint);
	void enablePID(bool enable);
#endif

};

#endif
