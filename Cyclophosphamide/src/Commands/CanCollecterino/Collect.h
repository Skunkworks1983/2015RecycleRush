#ifndef PUT_UP_H
#define PUT_UP_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"
#include "Arms/Induct.h"
#include "Arms/MoveWrist.h"

class Collect: public CommandGroup {
public:
	Collect(Induct::State direction = Induct::forward, MoveWrist::State state =
			MoveWrist::close);
};

#endif
