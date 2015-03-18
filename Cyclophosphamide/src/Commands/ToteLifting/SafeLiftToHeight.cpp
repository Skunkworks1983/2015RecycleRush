#include <Commands/CanCollecterino/Arms/MoveWrist.h>
#include <Commands/CanCollecterino/Craaaw/CraaawActuate.h>
#include <Commands/ToteIntake/EnableIntake.h>
#include <Commands/ToteLifting/LiftToHeight.h>
#include <Commands/ToteLifting/SafeLiftToHeight.h>
#include <RobotMap.h>

SafeLiftToHeight::SafeLiftToHeight(double destination, bool isCraaawSafe) {
	if(destination==TOTE_LIFTER_LOAD_HEIGHT){
		AddSequential(new EnableIntake(true));
	} else {
		AddSequential(new EnableIntake(false));
	}
	if (isCraaawSafe) {
		AddSequential(new CraaawActuate(CraaawActuate::close));
	}
	AddSequential(new MoveWrist(MoveWrist::open));
	AddSequential(new LiftToHeight(destination));
}
