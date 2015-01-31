#ifndef UpdateCompressor_H
#define UpdateCompressor_H

#include "../CommandBase.h"
#include "WPILib.h"

class UpdateCompressor: public CommandBase
{
private:
	int ticksSinceUpdate;
public:
	UpdateCompressor();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
