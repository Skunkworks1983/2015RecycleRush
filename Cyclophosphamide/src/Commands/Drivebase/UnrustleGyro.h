#ifndef UnrustleGyro_H
#define UnrustleGyro_H

#include "../../CommandBase.h"
#include "WPILib.h"

class UnrustleGyro: public CommandBase
{
public:
	/**
	 * Sets the drivebase PID to the current position
	 */
	UnrustleGyro();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
