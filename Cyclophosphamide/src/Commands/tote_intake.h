#ifndef tote_intake_H
#define tote_intake_H

#include "../CommandBase.h"
#include "WPILib.h"

class tote_intake: public CommandBase
{
public:
	tote_intake();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
