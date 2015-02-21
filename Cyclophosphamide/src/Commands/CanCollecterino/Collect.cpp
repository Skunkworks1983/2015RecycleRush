#include <Commands/CanCollecterino/Collect.h>
#include "Arms/Induct.h"
#include "Arms/MoveWrist.h"
Collect::Collect() {
	AddSequential(new MoveWrist(MoveWrist::close));
	AddSequential(new Induct(Induct::forward));
}
