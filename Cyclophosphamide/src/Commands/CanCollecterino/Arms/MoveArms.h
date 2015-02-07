#ifndef LIFT_ARMS_H
#define LIFT_ARMS_H

#include "../../../CommandBase.h"
#include "WPILib.h"

class MoveArms: public CommandBase
{
private:
	float setpoint;

public:
	MoveArms(bool up);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
