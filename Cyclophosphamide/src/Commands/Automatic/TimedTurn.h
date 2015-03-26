#ifndef TimedTurn_H
#define TimedTurn_H

#include "../../CommandBase.h"
#include "WPILib.h"

class TimedTurn: public CommandBase
{
private:
	float speed;
public:
	/**
	 * Who needs sensors amirite?
	 */
	TimedTurn(float timeout, float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
