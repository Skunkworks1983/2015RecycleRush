#ifndef COLLECT_H
#define COLLECT_H

#include "../../../CommandBase.h"
#include "WPILib.h"

class MoveWrist: public CommandBase
{
private:
	float setpoint;

public:
	MoveWrist(bool open);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
