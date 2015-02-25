#ifndef ToggleWhackMode_H
#define ToggleWhackMode_H

#include "../../../CommandBase.h"
#include "WPILib.h"

class ToggleWhackMode: public CommandBase
{
public:
	ToggleWhackMode();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
