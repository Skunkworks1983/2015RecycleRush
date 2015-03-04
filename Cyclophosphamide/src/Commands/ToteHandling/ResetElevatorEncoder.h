#ifndef ResetElevatorEncoder_H
#define ResetElevatorEncoder_H

#include "../../CommandBase.h"
#include "WPILib.h"

class ResetElevatorEncoder: public CommandBase {
public:
	ResetElevatorEncoder();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
