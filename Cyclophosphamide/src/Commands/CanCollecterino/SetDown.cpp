#include <Commands/CanCollecterino/SetDown.h>
#include "Arms/MoveWrist.h"
#include "Arms/MoveArms.h"
SetDown::SetDown()
{
	AddSequential(new MoveWrist(true));
	AddSequential(new MoveArms(false));
}
