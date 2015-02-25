#include "MoveArmsAndCollect.h"
#include "RobotMap.h"
#include "Arms/MoveArms.h"
#include "Arms/Induct.h"
#include "Arms/MoveWrist.h"
#include "Craaaw/CraaawActuate.h"

MoveArmsAndCollect::MoveArmsAndCollect(bool up) {
	if (up) {
		AddParallel(new CraaawActuate(DoubleSolenoid::kReverse));
		AddSequential(new MoveArms(CAN_POT_UP_POSITION));
		AddSequential(new Induct(Induct::forward, CAN_INDUCT_UP_TIMEOUT));
	} else {
		AddSequential(new MoveWrist(MoveWrist::close));
		AddParallel(new Induct(Induct::forward));
		AddSequential(new MoveArms(CAN_POT_DOWN_POSITION));
	}
}

MoveArmsAndCollect::MoveArmsAndCollect(bool up, double timeout) {
	if (up) {
		AddSequential(new MoveArms(CAN_POT_UP_POSITION));
		AddSequential(new Induct(Induct::stopped), timeout);
	} else {
		AddSequential(new MoveWrist(MoveWrist::close));
		AddParallel(new Induct(Induct::forward, timeout));
		AddSequential(new MoveArms(CAN_POT_DOWN_POSITION));
	}
}
