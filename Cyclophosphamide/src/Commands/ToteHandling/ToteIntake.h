#ifndef TOTE_INTAKE_H
#define TOTE_INTAKE_H

#include "../../CommandBase.h"
#include "WPILib.h"

class ToteIntake : public CommandBase
{
public:
	enum Direction {
		forward, reverse, stopped
	};
private:
	Direction direction;
public:
	ToteIntake(Direction direction);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
