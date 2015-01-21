#ifndef ResetGyro_H
#define ResetGyro_H

#include "../CommandBase.h"
#include "WPILib.h"

class ResetGyro: public CommandBase
{
private:
	bool firstIteration;
public:
	ResetGyro();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
