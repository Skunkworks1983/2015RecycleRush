#ifndef EnableIntake_H
#define EnableIntake_H

#include "../../CommandBase.h"
#include "WPILib.h"

/**
 * Enables or disables the PID on the tote intake
 */
class EnableIntake: public CommandBase
{
private:
	bool enable;
public:
	EnableIntake(bool enable);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
