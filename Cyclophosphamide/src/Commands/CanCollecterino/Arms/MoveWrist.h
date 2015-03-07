#ifndef COLLECT_H
#define COLLECT_H

#include "../../../CommandBase.h"
#include "WPILib.h"

/*!
 * Toggles the position of the wrists (opened or closed)
 * set the pneumatics to forward else reverse.
 */


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
