#ifndef DownUp_H
#define DownUp_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class DownUp: public CommandGroup
{
public:
	enum Position {
		carry, load
	};
	DownUp(Position position);
};

#endif
