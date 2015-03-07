#include "Whack.h"
#include "MoveArms.h"
#include "MoveWrist.h"

Whack::Whack() {
	AddParallel(new MoveWrist(MoveWrist::close));
	AddSequential(new MoveArms(CAN_POT_KNOCK_POSITION));
}
