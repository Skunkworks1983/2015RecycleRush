#include <Commands/Armerino/Craaaw/ActuateCanStabilizer.h>
#include <Commands/ToteLifting/SafeLiftToHeight.h>
#include "Score.h"
#include "RobotMap.h"

Score::Score() {
	AddParallel(new ActuateCanStabilizer(ActuateCanStabilizer::open));
	AddSequential(new SafeLiftToHeight(TOTE_LIFTER_FLOOR_HEIGHT));
}
