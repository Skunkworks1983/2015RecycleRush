#include <Commands/Armerino/CollectCan.h>

Collect::Collect(Induct::State direction, MoveWrist::State state) {
	AddSequential(new MoveWrist(state));
	AddSequential(new Induct(direction));
}
