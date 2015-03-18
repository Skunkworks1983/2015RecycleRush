#include <Commands/Armerino/Arms/MoveWrist.h>
#include <Commands/Armerino/Craaaw/CraaawActuate.h>
#include <Commands/ToteLifting/LiftToHeight.h>
#include <Commands/ToteLifting/SafeLiftToHeight.h>

SafeLiftToHeight::SafeLiftToHeight(double destination, bool isCraaawSafe) {
	if (isCraaawSafe) {
		AddSequential(new CraaawActuate(CraaawActuate::close));
	}
	AddSequential(new MoveWrist(MoveWrist::open));
	AddSequential(new LiftToHeight(destination));
}
