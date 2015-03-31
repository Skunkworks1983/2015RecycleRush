#include <Commands/Armerino/Arms/Induct.h>
#include <Commands/Armerino/Arms/MoveArms.h>
#include <Commands/Armerino/Arms/MoveWrist.h>
#include <Commands/Armerino/Arms/ToggleArms.h>
#include <Commands/Armerino/Craaaw/ActuateCanStabilizer.h>
#include <Commands/Armerino/MoveArmsFancy.h>
#include "RobotMap.h"

MoveArmsFancy::MoveArmsFancy(State state) {
	switch (state) {
	case State::up:
		AddParallel(new ActuateCanStabilizer(ActuateCanStabilizer::open));
		AddSequential(new MoveArms(CAN_POT_UP_POSITION));
//		AddSequential(new Induct(Induct::forward, CAN_INDUCT_UP_TIMEOUT)); Probably not be needed with fancy craaaw
		break;
	case State::down:
		AddSequential(new MoveWrist(MoveWrist::open));
		AddSequential(new MoveArms(CAN_POT_DOWN_POSITION));
		break;
	case State::toggle:
		AddParallel(new ActuateCanStabilizer(ActuateCanStabilizer::open));
		AddSequential(new MoveWrist(MoveWrist::close));
		AddSequential(new ToggleArms());
		break;
	}
}
