#ifndef NEW_TOTE_INTAKE_H
#define NEW_TOTE_INTAKE_H

#include "../../CommandBase.h"
#include "WPILib.h"

class NewToteIntake: public CommandBase {
public:
	enum Direction {
		forward, reverse, stopped
	};
private:
	Direction direction;
public:
	NewToteIntake(Direction direction, double timeout = 0);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
