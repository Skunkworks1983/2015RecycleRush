#include <Commands/CanCollecterino/CanToCraaawTransfer.h>
#include "RobotMap.h"
#include "Arms/MoveWrist.h"
#include "Arms/MoveArms.h"
#include "Craaaw/CraaawActuate.h"

CanToCraaawTransfer::CanToCraaawTransfer()
{
	AddSequential(new CraaawActuate(false));
	AddSequential(new MoveWrist(MoveWrist::open));
}
