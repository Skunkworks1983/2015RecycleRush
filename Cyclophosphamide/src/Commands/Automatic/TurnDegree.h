#ifndef TurnDegree_H
#define TurnDegree_H

#include "../../CommandBase.h"
#include "WPILib.h"

class TurnDegree: public CommandBase
{
private:
	float targetAngle;
	float angleRemaining;
public:
	TurnDegree(float targetAngle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
