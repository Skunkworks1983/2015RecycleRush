#include <Commands/Armerino/Arms/Induct.h>
#include <Commands/Armerino/Arms/MoveArms.h>
#include <Commands/Armerino/Arms/MoveWrist.h>
#include <Commands/Armerino/Craaaw/ActuateCanStabilizer.h>
#include <Commands/Armerino/TransferCan.h>

#include <Commands/ToteLifting/SafeLiftToHeight.h>
#include <Commands/WaitCommand.h>
#include <RobotMap.h>

TransferCan::TransferCan() {
	AddSequential(new MoveArms(CAN_POT_UP_POSITION));
	AddSequential(new Induct(CAN_GRAB_SPEED, .5));
	AddSequential(new ActuateCanStabilizer(ActuateCanStabilizer::close));
	AddSequential(new WaitCommand(.25));
	AddSequential(new MoveWrist(MoveWrist::open));
	AddSequential(new SafeLiftToHeight(TOTE_LIFTER_LOAD_HEIGHT));
}
