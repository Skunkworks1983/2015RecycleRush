#include <Commands/Armerino/Arms/MoveWrist.h>
#include <Commands/Armerino/Craaaw/CraaawActuate.h>
#include <Commands/ToteLifting/LiftToHeight.h>
#include <Commands/ToteLifting/SafeDownUp.h>

SafeDownUp::SafeDownUp(DownUp::Position pos) {
	AddSequential(new MoveWrist(MoveWrist::open));
	AddSequential(new DownUp(pos));
}
