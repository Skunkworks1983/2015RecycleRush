#ifndef ToteLifter_H
#define ToteLifter_H

#include "../../CommandBase.h"
#include "WPILib.h"

class LiftToHeight : public CommandBase
{
private:
	double destination;
	double startingPos;
	double motorSpeed;
	double oldDiff;
public:
	LiftToHeight(double destination);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
