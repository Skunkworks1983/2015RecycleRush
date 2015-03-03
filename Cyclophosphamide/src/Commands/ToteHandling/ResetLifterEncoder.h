#ifndef ResetLifterEncoder_H
#define ResetLifterEncoder_H

#include "../../CommandBase.h"
#include "WPILib.h"

class ResetLifterEncoder: public CommandBase
{
public:
	ResetLifterEncoder();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
