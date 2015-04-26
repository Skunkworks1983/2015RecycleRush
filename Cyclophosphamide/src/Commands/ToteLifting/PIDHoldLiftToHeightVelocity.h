#ifndef PIDHoldLiftToHeightVelocity_H
#define PIDHoldLiftToHeightVelocity_H

#include <CommandBase.h>

class PIDHoldLiftToHeightVelocity: public CommandBase
{
private:
	double speed;
public:
	PIDHoldLiftToHeightVelocity(double speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
