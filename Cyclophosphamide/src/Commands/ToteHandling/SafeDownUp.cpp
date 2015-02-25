#include "SafeDownUp.h"
#include "../CanCollecterino/Arms/MoveWrist.h"
#include "../CanCollecterino/Craaaw/CraaawActuate.h"
#include "LiftToHeight.h"

SafeDownUp::SafeDownUp(DownUp::Position pos)
{
	AddSequential(new MoveWrist(MoveWrist::open));
	AddSequential(new DownUp(pos));
}
