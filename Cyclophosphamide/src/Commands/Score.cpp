#include <Commands/ToteLifting/SafeLiftToHeight.h>
#include "Score.h"
#include "RobotMap.h"
#include "CanCollecterino/Craaaw/CraaawActuate.h"

Score::Score() {
	AddParallel(new CraaawActuate(CraaawActuate::open));
	AddSequential(new SafeLiftToHeight(TOTE_LIFTER_FLOOR_HEIGHT));
}
