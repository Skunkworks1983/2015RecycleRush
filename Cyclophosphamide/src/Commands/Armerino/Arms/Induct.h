#ifndef INDUCTERINO_H
#define INDUCTERINO_H

#include "../../../CommandBase.h"
#include "WPILib.h"

class Induct: public CommandBase {
public:
	enum State {
		forward, reverse, stopped
	};
	enum Mode {
		tote, can
	};
private:
	State state;
	Mode mode;
public:
	Induct(State state, Mode mode = can);
	Induct(State state, double timeout, Mode mode = can);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
