#ifndef TurnToThenDrive_H
#define TurnToThenDrive_H

#include <Commands/CommandGroup.h>

class TurnToThenDrive: public CommandGroup {
public:
	TurnToThenDrive(float targetAngle);
};

#endif
