#include <Commands/Armerino/Arms/Induct.h>
#include <Commands/Armerino/Arms/MoveWrist.h>
#include <Commands/Armerino/CanToCraaawTransfer.h>
#include <Commands/Armerino/Craaaw/CraaawActuate.h>
#include <Commands/ToteLifting/LiftToHeight.h>
#include <Commands/WaitCommand.h>
#include <RobotMap.h>

CanToCraaawTransfer::CanToCraaawTransfer() {
	AddSequential(new Induct(Induct::forward, .5));
	AddSequential(new CraaawActuate(CraaawActuate::close));
	AddSequential(new WaitCommand(.25));
	AddSequential(new MoveWrist(MoveWrist::open));
	AddSequential(new LiftToHeight(TOTE_LIFTER_LOAD_HEIGHT));
}
