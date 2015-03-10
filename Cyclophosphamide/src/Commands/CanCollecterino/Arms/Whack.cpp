#include "Whack.h"
#include "MoveArms.h"
#include "MoveWrist.h"

Whack::Whack() {
	AddParallel(new MoveArms(CAN_POT_KNOCK_POSITION));
	AddSequential(new WaitCommand(.3));
	AddSequential(new MoveWrist(MoveWrist::close));
}
