#ifndef LiftRelative_H
#define LiftRelative_H

#include "../../CommandBase.h"
#include "WPILib.h"

class LiftRelative: public CommandBase
{
private:
	float delta;
	float destination;
public:
	LiftRelative(float delta);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
