#ifndef Craterino_H
#define Craterino_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 * This is the crate lifter
 */
class ToteLifterino: public Subsystem
{
private:
	Encoder *positionEncoder;
	Talon *RightLifter;
	Talon *LeftLifter;
	int destination;
	bool at_destination;
public:
	ToteLifterino();
	void InitDefaultCommand();
	int getStackerPosition();
	bool closeEnough(int value, int constant);
	void setDestination(int position);
	bool isAtDestination();
};

#endif
