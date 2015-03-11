#include <Commands/CanCollecterino/CanToCraaawTransfer.h>
#include <Commands/ToteLifting/LiftToHeight.h>
#include "RobotMap.h"
#include "Arms/MoveWrist.h"
#include "Arms/MoveArms.h"
#include "Craaaw/CraaawActuate.h"

CanToCraaawTransfer::CanToCraaawTransfer() {
	AddSequential(new CraaawActuate(CraaawActuate::close));
	AddSequential(new WaitCommand(.25));
	AddSequential(new MoveWrist(MoveWrist::open));
	AddSequential(new LiftToHeight(TOTE_LIFTER_LOAD_HEIGHT));
}
