#include "DownUp.h"
#include "RobotMap.h"
#include "LiftToHeight.h"

DownUp::DownUp(DownUp::Position pos)
{
	AddSequential(new LiftToHeight(TOTE_LIFTER_FLOOR_HEIGHT));
	switch(pos) {
	case Position::carry:
		AddSequential(new LiftToHeight(TOTE_LIFTER_CARRY_HEIGHT));
		break;
	case Position::load:
		AddSequential(new LiftToHeight(TOTE_LIFTER_TWO_TOTE));
		break;
	}
}
