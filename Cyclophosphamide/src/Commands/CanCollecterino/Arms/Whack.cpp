#include "Whack.h"
#include "MoveArms.h"
#include "MoveWrist.h"

Whack::Whack() {
	AddSequential(new MoveArms(CAN_POT_KNOCK_POSITION));
	AddSequential(new MoveWrist(MoveWrist::close));
}
