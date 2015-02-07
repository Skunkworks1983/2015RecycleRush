#ifndef CraaawActuate_H
#define CraaawActuate_H

#include "../../../CommandBase.h"
#include "WPILib.h"

class CraaawActuate: public CommandBase
{
private:
	bool waitForInput;

public:
	CraaawActuate(bool waitForInput);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
