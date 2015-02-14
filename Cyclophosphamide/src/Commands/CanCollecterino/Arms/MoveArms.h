#ifndef MOVE_ARMS_H
#define MOVE_ARMS_H

#include "../../../CommandBase.h"
#include "WPILib.h"

class MoveArms: public CommandBase
{
private:
	float setpoint;
	int fuck;

public:
	MoveArms(bool up);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
