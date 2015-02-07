#ifndef LIFT_ARMS_H
#define LIFT_ARMS_H

#include "../../../CommandBase.h"
#include "WPILib.h"

class Induct: public CommandBase
{
public:
	Induct();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
