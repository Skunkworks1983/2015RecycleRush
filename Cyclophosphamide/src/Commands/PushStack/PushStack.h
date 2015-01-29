#ifndef PushStack_H
#define PushStack_H

#include "../../CommandBase.h"
#include "WPILib.h"


class PushStack: public CommandBase
{
private:
	StackPusher::PushState state;

public:
	PushStack(StackPusher::PushState state, float timeout);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
