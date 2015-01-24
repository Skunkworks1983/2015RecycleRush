#ifndef Craterino_H
#define Craterino_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <vector>
using std::vector;

/**
 * This is the crate lifter
 */
class ToteLifterino: public Subsystem
{
private:
	Encoder *positionEncoder;
	Talon *RightLifter;
	Talon *LeftLifter;
	vector<int> destinations;
public:
	ToteLifterino();
	void InitDefaultCommand();
	int getStackerPosition();
	bool closeEnough(int value, int constant);
	void addDestination(int position);
	bool At(int position);
	int getValue(int key);

	void checkAtDestination();
	void driveTowardsDestination();
};

#endif
