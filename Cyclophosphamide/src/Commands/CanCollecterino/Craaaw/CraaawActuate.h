#ifndef CraaawActuate_H
#define CraaawActuate_H

#include "../../../CommandBase.h"
#include "WPILib.h"

class CraaawActuate: public CommandBase
{
/*!
 * Checks if the craaaw is unactuated and actuates it
 */
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
