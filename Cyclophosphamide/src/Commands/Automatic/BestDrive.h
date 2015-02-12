#ifndef BetterDrive_H
#define BetterDrive_H

#include "../../CommandBase.h"
#include "WPILib.h"

class BestDrive: public CommandBase
{
public:
	enum Direction {
		forward, backward, left, right
	};
private:
	float targetDistance;
	Direction direction;
public:
	BestDrive(float distance, Direction direction);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
