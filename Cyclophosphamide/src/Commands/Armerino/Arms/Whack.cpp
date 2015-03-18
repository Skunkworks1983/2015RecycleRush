#include <Commands/Armerino/Arms/MoveArms.h>
#include <Commands/Armerino/Arms/MoveWrist.h>
#include <Commands/Armerino/Arms/Whack.h>

Whack::Whack() {
	AddParallel(new MoveArms(CAN_POT_KNOCK_POSITION));
	AddSequential(new WaitCommand(.3));
	AddSequential(new MoveWrist(MoveWrist::close));
}
