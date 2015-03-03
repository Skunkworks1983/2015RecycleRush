#include <Commands/CanCollecterino/SetDown.h>
#include "Arms/MoveWrist.h"
#include "Arms/MoveArms.h"
SetDown::SetDown()
{
	AddSequential(new MoveWrist(MoveWrist::open));
	AddSequential(new MoveArms(false));
}
