#include "SafeLiftToHeight.h"
#include "../CanCollecterino/Arms/MoveWrist.h"
#include "../CanCollecterino/Craaaw/CraaawActuate.h"
#include "LiftToHeight.h"

SafeLiftToHeight::SafeLiftToHeight(double destination, bool isCraaawSafe) {
	if (isCraaawSafe) {
		AddSequential(new CraaawActuate(DoubleSolenoid::kForward));
	}
	AddSequential(new MoveWrist(MoveWrist::open));
	AddSequential(new LiftToHeight(destination));
}
