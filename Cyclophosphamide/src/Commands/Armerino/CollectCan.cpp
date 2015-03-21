#include <Commands/Armerino/CollectCan.h>

Collect::Collect(float speed, MoveWrist::State state) {
	AddSequential(new MoveWrist(state));
	AddSequential(new Induct(speed));
}
