#ifndef ZeroElevatorMag_H
#define ZeroElevatorMag_H

#include "../../CommandBase.h"
#include "WPILib.h"

/**
 * To be ran in auto so that it can be zeroed by the time
 * teleop begins. Code and values still need to be tested.
 */
class ZeroElevatorMag: public CommandBase {
private:
	bool triggered;
	bool zeroed;
public:
	ZeroElevatorMag();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
