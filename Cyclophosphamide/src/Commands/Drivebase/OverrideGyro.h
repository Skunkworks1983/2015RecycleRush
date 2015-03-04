#ifndef OverrideGyro_H
#define OverrideGyro_H

#include "../../CommandBase.h"
#include "WPILib.h"

class OverrideGyro: public CommandBase {
private:
	bool override;
public:
	OverrideGyro(bool override);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
