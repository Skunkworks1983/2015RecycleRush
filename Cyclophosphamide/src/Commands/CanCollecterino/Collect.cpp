#include <Commands/CanCollecterino/Collect.h>
#include "Arms/Induct.h"
#include "Arms/MoveWrist.h"
Collect::Collect() {
	AddSequential(new MoveWrist(false));
	AddSequential(new Induct());
}

