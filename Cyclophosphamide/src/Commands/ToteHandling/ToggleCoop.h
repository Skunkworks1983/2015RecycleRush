#ifndef ToggleCoop_H
#define ToggleCoop_H

#include "../../CommandBase.h"
#include "WPILib.h"

class ToggleCoop: public CommandBase
{
public:
	ToggleCoop();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
