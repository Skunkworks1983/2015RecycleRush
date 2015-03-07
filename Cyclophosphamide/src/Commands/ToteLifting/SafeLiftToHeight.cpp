#include <Commands/ToteLifting/LiftToHeight.h>
#include <Commands/ToteLifting/SafeLiftToHeight.h>
#include "../CanCollecterino/Arms/MoveWrist.h"
#include "../CanCollecterino/Craaaw/CraaawActuate.h"

SafeLiftToHeight::SafeLiftToHeight(double destination, bool isCraaawSafe) {
	if (isCraaawSafe) {
		AddSequential(new CraaawActuate(CraaawActuate::close));
	}
	AddSequential(new MoveWrist(MoveWrist::open));
	AddSequential(new LiftToHeight(destination));
}
