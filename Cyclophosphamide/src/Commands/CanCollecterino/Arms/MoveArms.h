#ifndef MOVE_ARMS_H
#define MOVE_ARMS_H

#include "../../../CommandBase.h"
#include "WPILib.h"
/*!
 * Move arms to a user specified location
 */
private:
class MoveArms: public CommandBase {
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
