#ifndef INDUCTERINO_H
#define INDUCTERINO_H

#include "../../../CommandBase.h"
#include "WPILib.h"

class Induct: public CommandBase
{
/*!
 * Sets the motor speed of the can grabbing mecanum motors
 */
private:
	int kek;
public:
	Induct();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
