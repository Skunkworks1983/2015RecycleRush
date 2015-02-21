#include "MoveArmsAndCollect.h"
#include "RobotMap.h"
#include "Arms/MoveArms.h"
#include "Arms/Induct.h"
#include "Arms/MoveWrist.h"

MoveArmsAndCollect::MoveArmsAndCollect(bool up) {
	if (up) {
		AddSequential(new MoveArms(CAN_POT_UP_POSITION));
		AddSequential(new Induct(Induct::stopped));
	} else {
		AddSequential(new MoveWrist(MoveWrist::close));
		AddParallel(new Induct(Induct::forward));
		AddSequential(new MoveArms(CAN_POT_DOWN_POSITION));
	}
}
