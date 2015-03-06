#ifndef INDUCTERINO_H
#define INDUCTERINO_H

#include "../../../CommandBase.h"
#include "WPILib.h"
/*!
 * Sets the motor speed of the can grabbing mecanum motors to zero
 */
class Induct: public CommandBase
{
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
