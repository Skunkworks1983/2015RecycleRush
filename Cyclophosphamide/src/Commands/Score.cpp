#include <Commands/Armerino/Craaaw/CraaawActuate.h>
#include <Commands/ToteLifting/SafeLiftToHeight.h>
#include "Score.h"
#include "RobotMap.h"

Score::Score() {
	AddParallel(new CraaawActuate(CraaawActuate::open));
	AddSequential(new SafeLiftToHeight(TOTE_LIFTER_FLOOR_HEIGHT));
}
