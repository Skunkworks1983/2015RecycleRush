#ifndef COLLECT_H
#define COLLECT_H

#include "../CommandBase.h"
#include "WPILib.h"

class Collect: public CommandBase
{
public:
	Collect();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
