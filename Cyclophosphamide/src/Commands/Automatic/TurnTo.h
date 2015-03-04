#ifndef TURN_DEGREE_H
#define TURN_DEGREE_H

#include "../../CommandBase.h"
#include "WPILib.h"

class TurnTo: public CommandBase {
private:
	float targetAngle;
	float angleRemaining;
public:
	TurnTo(float targetAngle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
