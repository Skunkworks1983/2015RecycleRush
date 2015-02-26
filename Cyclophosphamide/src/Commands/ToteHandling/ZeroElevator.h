#ifndef ZeroElevator_H
#define ZeroElevator_H

#include "../../CommandBase.h"
#include "WPILib.h"

/**
 * To be ran in auto so that it can be zeroed by the time
 * teleop begins. Code and values still need to be tested.
 */
class ZeroElevator: public CommandBase {
private:
	int zeroCount;
	double oldEncoderTick;
public:
	ZeroElevator();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
