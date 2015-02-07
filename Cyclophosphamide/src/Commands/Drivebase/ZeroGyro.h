#ifndef ResetGyro_H
#define ResetGyro_H

#include "../../CommandBase.h"
#include "WPILib.h"

class ZeroGyro: public CommandBase
{
private:
	bool firstIteration;
public:
	ZeroGyro();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
