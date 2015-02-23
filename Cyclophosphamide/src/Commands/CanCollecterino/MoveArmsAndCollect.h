#ifndef MoveArmsAndCollect_H
#define MoveArmsAndCollect_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class MoveArmsAndCollect: public CommandGroup {
public:
	MoveArmsAndCollect(bool up);
	MoveArmsAndCollect(bool up, double timeout);
};

#endif
