#ifndef SafeDownUp_H
#define SafeDownUp_H

#include <Commands/ToteLifting/DownUp.h>
#include "Commands/CommandGroup.h"
#include "WPILib.h"

class SafeDownUp: public CommandGroup {
public:
	SafeDownUp(DownUp::Position pos);
};

#endif
