#ifndef ToggleArms_H
#define ToggleArms_H

#include "../../../CommandBase.h"
#include "WPILib.h"

class ToggleArms: public CommandBase {
public:
	ToggleArms();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
