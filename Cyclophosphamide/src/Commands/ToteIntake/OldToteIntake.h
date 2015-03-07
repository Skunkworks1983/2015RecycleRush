#ifndef TOTE_INTAKE_H
#define TOTE_INTAKE_H

#include "../../CommandBase.h"
#include "WPILib.h"

class OldToteIntake : public CommandBase
{
public:
	enum Direction {
		forward, reverse, stopped
	};
private:
	Direction direction;
public:
	OldToteIntake(Direction direction);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
