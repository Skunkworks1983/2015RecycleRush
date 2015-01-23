#ifndef LOWER_ARMS_H
#define LOWER_ARMS_H

#include "../CommandBase.h"
#include "WPILib.h"

class LowerArms: public CommandBase
{
public:
	LowerArms();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
