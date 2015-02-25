#include <Commands/CanCollecterino/CanToCraaawTransfer.h>
#include "RobotMap.h"
#include "Arms/MoveWrist.h"
#include "Arms/MoveArms.h"
#include "Craaaw/CraaawActuate.h"
#include "../ToteHandling/LiftRelative.h"

CanToCraaawTransfer::CanToCraaawTransfer() {
	AddSequential(new CraaawActuate(DoubleSolenoid::kForward));
	AddParallel(new MoveWrist(MoveWrist::open));
	AddSequential(new LiftRelative(BOUNCE_HEIGHT));
	AddSequential(new LiftRelative(-BOUNCE_HEIGHT));
}
