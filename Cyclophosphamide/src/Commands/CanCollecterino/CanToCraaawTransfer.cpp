#include <Commands/CanCollecterino/CanToCraaawTransfer.h>
#include "RobotMap.h"
#include "Arms/MoveWrist.h"
#include "Arms/MoveArms.h"

CanToCraaawTransfer::CanToCraaawTransfer()
{
	if(CommandBase::canCollecterino->getSetpoint() == CAN_POT_DOWN_POSITION) {
		AddSequential(new MoveArms(CAN_POT_UP_POSITION));
		AddSequential(new MoveWrist(false));
	} else {
		AddSequential(new MoveWrist(true));
		AddSequential(new MoveArms(CAN_POT_DOWN_POSITION));
	}
}
