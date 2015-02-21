#ifndef ZeroElevator_H
#define ZeroElevator_H

#include "../../CommandBase.h"
#include "WPILib.h"

class ZeroElevator: public CommandBase
{
private:
	bool zeroAtBottom;
public:
	ZeroElevator(bool zeroAtBottom);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
