#include <Commands/CanCollecterino/MoveArmsFancy.h>
#include "RobotMap.h"
#include "Arms/MoveArms.h"
#include "Arms/Induct.h"
#include "Arms/MoveWrist.h"
#include "Craaaw/CraaawActuate.h"

MoveArmsFancy::MoveArmsFancy(bool up) {
	if (up) {
		AddParallel(new CraaawActuate(DoubleSolenoid::kReverse));
		AddSequential(new MoveArms(CAN_POT_UP_POSITION));
//		AddSequential(new Induct(Induct::forward, CAN_INDUCT_UP_TIMEOUT)); Probably not be needed with fancy craaaw
	} else {
		AddSequential(new MoveWrist(MoveWrist::close));
		AddSequential(new MoveArms(CAN_POT_DOWN_POSITION));
	}
}
