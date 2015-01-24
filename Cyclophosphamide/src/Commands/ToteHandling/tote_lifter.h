#ifndef tote_lifter_H
#define tote_lifter_H

#include "../../CommandBase.h"
#include "WPILib.h"

class tote_lifter: public CommandBase
{
public:
	tote_lifter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
