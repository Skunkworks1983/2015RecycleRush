#include <Commands/Armerino/Arms/MoveArms.h>
#include <Commands/Armerino/Arms/MoveArmsKnock.h>
#include <Commands/Armerino/Arms/MoveWrist.h>

MoveArmsKnock::MoveArmsKnock() {
	AddParallel(new MoveArms(CAN_POT_KNOCK_POSITION));
	AddSequential(new WaitCommand(.3));		//This is so that the wrists do not close when in up position
	AddSequential(new MoveWrist(MoveWrist::close));
}
