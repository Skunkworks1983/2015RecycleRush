#ifndef SafeDownUp_H
#define SafeDownUp_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"
#include "DownUp.h"

class SafeDownUp: public CommandGroup {
public:
	SafeDownUp(DownUp::Position pos);
};

#endif
