#ifndef MoveArmsFancy_H
#define MoveArmsFancy_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class MoveArmsFancy: public CommandGroup {
public:
	enum State {
		up, down, toggle
	};
	MoveArmsFancy(State state);
};

#endif
