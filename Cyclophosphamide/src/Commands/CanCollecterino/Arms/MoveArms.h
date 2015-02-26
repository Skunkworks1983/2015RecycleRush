#ifndef MOVE_ARMS_H
#define MOVE_ARMS_H

#include "../../../CommandBase.h"
#include "WPILib.h"

class MoveArms: public CommandBase {
/*!
 * Move arms to a user specified location
 */
private:
	float setpoint;

public:
	MoveArms(float setpoint);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
