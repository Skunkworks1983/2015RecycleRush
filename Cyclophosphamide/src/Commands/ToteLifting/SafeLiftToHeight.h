#ifndef SafeLiftToHeight_H
#define SafeLiftToHeight_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class SafeLiftToHeight: public CommandGroup {
public:
	SafeLiftToHeight(double destination, bool isCraaawSafe = false);
};

#endif
