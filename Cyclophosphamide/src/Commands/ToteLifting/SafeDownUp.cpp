#include <Commands/ToteLifting/LiftToHeight.h>
#include <Commands/ToteLifting/SafeDownUp.h>
#include "../CanCollecterino/Arms/MoveWrist.h"
#include "../CanCollecterino/Craaaw/CraaawActuate.h"

SafeDownUp::SafeDownUp(DownUp::Position pos) {
	AddSequential(new MoveWrist(MoveWrist::open));
	AddSequential(new DownUp(pos));
}
