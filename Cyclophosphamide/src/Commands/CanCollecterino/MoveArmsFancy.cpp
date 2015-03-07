#include <Commands/CanCollecterino/MoveArmsFancy.h>
#include "RobotMap.h"
#include "Arms/MoveArms.h"
#include "Arms/Induct.h"
#include "Arms/MoveWrist.h"
#include "Arms/ToggleArms.h"
#include "Craaaw/CraaawActuate.h"

MoveArmsFancy::MoveArmsFancy(State state) {
	switch (state) {
	case State::up:
		AddParallel(new CraaawActuate(CraaawActuate::open));
		AddSequential(new MoveArms(CAN_POT_UP_POSITION));
//		AddSequential(new Induct(Induct::forward, CAN_INDUCT_UP_TIMEOUT)); Probably not be needed with fancy craaaw
		break;
	case State::down:
		AddSequential(new MoveWrist(MoveWrist::close));
		AddSequential(new MoveArms(CAN_POT_DOWN_POSITION));
		break;
	case State::toggle:
		AddParallel(new CraaawActuate(CraaawActuate::open));
		AddSequential(new MoveWrist(MoveWrist::close));
		AddSequential(new ToggleArms());
		break;
	}
}
