#include <Commands/CanCollecterino/CanToCraaawTransfer.h>
#include "RobotMap.h"
#include "Arms/MoveWrist.h"
#include "Arms/MoveArms.h"

CanToCraaawTransfer::CanToCraaawTransfer()
{
	AddSequential(new MoveArms(CAN_POT_UP_POSITION));
	AddSequential(new MoveWrist(false));
}
