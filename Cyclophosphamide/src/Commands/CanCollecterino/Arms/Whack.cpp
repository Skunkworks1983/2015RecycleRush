#include "Whack.h"
#include "ToggleWhackMode.h"
#include "MoveWrist.h"

Whack::Whack()
{
	AddParallel(new MoveWrist(MoveWrist::close));
	AddSequential(new ToggleWhackMode());
}
