#include <Commands/Armerino/Arms/Induct.h>
#include <Commands/Armerino/Arms/MoveArms.h>
#include <Commands/Armerino/Arms/MoveWrist.h>
#include <Commands/Armerino/CanToCraaawTransfer.h>
#include <Commands/Armerino/Craaaw/CraaawActuate.h>

#include <Commands/ToteLifting/SafeLiftToHeight.h>
#include <Commands/WaitCommand.h>
#include <RobotMap.h>

CanToCraaawTransfer::CanToCraaawTransfer() {
	AddSequential(new MoveArms(CAN_POT_UP_POSITION));
	AddSequential(new Induct(CAN_GRAB_SPEED, .5));
	AddSequential(new CraaawActuate(CraaawActuate::close));
	AddSequential(new WaitCommand(.25));
	AddSequential(new MoveWrist(MoveWrist::open));
	AddSequential(new SafeLiftToHeight(TOTE_LIFTER_LOAD_HEIGHT));
}
