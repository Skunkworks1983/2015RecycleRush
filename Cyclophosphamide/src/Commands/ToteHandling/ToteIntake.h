#ifndef ToteIntake_H
#define ToteIntake_H

#include "../../CommandBase.h"
#include "WPILib.h"

class ToteIntake : public CommandBase
{
public:
	ToteIntake();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
