#include <Commands/CanCollecterino/Arms/Induct.h>
#include <Commands/CanCollecterino/Arms/MoveWrist.h>
#include <Commands/CanCollecterino/CanToCraaawTransfer.h>
#include <Commands/CanCollecterino/Craaaw/CraaawActuate.h>
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
