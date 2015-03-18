#ifndef PUT_UP_H
#define PUT_UP_H

#include <Commands/Armerino/Arms/Induct.h>
#include <Commands/Armerino/Arms/MoveWrist.h>
#include "Commands/CommandGroup.h"
#include "WPILib.h"

class Collect: public CommandGroup {
public:
	Collect(Induct::State direction = Induct::forward, MoveWrist::State state =
			MoveWrist::close);
};

#endif
