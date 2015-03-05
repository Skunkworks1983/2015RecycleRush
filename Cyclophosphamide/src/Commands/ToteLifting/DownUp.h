#ifndef DownUpToggle_H
#define DownUpToggle_H

#include "../../CommandBase.h"
#include "WPILib.h"

class DownUp: public CommandBase {
public:
	enum Position {
		carry, load
	};
private:
	Position pos;
	float destination;
public:
	DownUp(Position pos);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
