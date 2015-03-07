#ifndef INDUCTERINO_H
#define INDUCTERINO_H

#include "../../../CommandBase.h"
#include "WPILib.h"

/*!
 * Sets the motor speed of the can grabbing mecanum motors to zero
 */

class Induct: public CommandBase {
public:
	enum State {
		forward, reverse, stopped
	};
private:
	State state;
public:
	};
	Induct(State state);
	Induct(State state, double timeout);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
