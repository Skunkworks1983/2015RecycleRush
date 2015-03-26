#ifndef TurnRelative_H
#define TurnRelative_H

#include "../../CommandBase.h"
#include "WPILib.h"

class TurnRelative: public CommandBase
{
private:
	float delta;
	float targetAngle;
public:
	TurnRelative(float delta);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
