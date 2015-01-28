#ifndef ToteLifter_H
#define ToteLifter_H

#include "../../CommandBase.h"
#include "WPILib.h"

class ToteLifter : public CommandBase
{
public:
	ToteLifter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
