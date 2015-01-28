#ifndef PushStack_H
#define PushStack_H

#include "../CommandBase.h"
#include "WPILib.h"

class PushStack: public CommandBase
{
public:
	PushStack();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
