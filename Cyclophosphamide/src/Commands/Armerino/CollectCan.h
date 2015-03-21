#ifndef PUT_UP_H
#define PUT_UP_H

#include <Commands/Armerino/Arms/Induct.h>
#include <Commands/Armerino/Arms/MoveWrist.h>
#include "Commands/CommandGroup.h"
#include "WPILib.h"

class Collect: public CommandGroup {
public:
	Collect(float speed = CAN_GRAB_SPEED, MoveWrist::State state =
			MoveWrist::close);
};

#endif
