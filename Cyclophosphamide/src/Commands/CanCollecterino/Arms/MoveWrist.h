#ifndef COLLECT_H
#define COLLECT_H

#include "../../../CommandBase.h"
#include "WPILib.h"
/*!
 * Toggles the position of the wrists (opened or closed)
 * set the pneumatics to forward else reverse.
 */
class MoveWrist: public CommandBase
{
private:
	DoubleSolenoid::Value setpoint;

public:
	MoveWrist(bool open);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
