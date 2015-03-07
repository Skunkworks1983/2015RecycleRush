#ifndef CraaawActuate_H
#define CraaawActuate_H

#include "../../../CommandBase.h"
#include "WPILib.h"

class CraaawActuate: public CommandBase {
public:
	enum State {
		open, close, toggle
	};
private:
	State value;
public:
	CraaawActuate(State value);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
