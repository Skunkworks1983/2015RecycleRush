#ifndef MOVE_WRIST_H
#define MOVE_WRIST_H

#include "../../../CommandBase.h"
#include "WPILib.h"

class MoveWrist: public CommandBase {
public:
	enum State {
		open, close, toggle
	};
private:
	State state;

public:
	MoveWrist(State state);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
