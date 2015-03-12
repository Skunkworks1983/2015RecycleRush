#ifndef CraaawActuate_H
#define CraaawActuate_H

#include "../../../CommandBase.h"
#include "WPILib.h"

/*!
 * Checks if the craaaw is unactuated and actuates it
 */

class CraaawActuate: public CommandBase {
public:
	enum State {
		open, close, toggle
	};
private:
	State value;
	float timeout;
public:
	CraaawActuate(State value, float timeout = -1);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
