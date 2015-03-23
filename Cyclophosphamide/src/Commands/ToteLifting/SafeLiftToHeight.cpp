#include <Commands/Armerino/Arms/MoveWrist.h>
#include <Commands/Armerino/Craaaw/CraaawActuate.h>
#include <Commands/ToteIntake/ToteIntake.h>
#include <Commands/ToteLifting/LiftToHeight.h>
#include <Commands/ToteLifting/SafeLiftToHeight.h>
#include <RobotMap.h>

SafeLiftToHeight::SafeLiftToHeight(double destination, bool isCraaawSafe) {
	if(destination==TOTE_LIFTER_LOAD_HEIGHT){
		AddSequential(new ToteIntake(TOTE_INTAKE_MOTOR_FULL));
	} else {
		AddSequential(new ToteIntake(0));
	}
	if (isCraaawSafe) {
		AddSequential(new CraaawActuate(CraaawActuate::close));
	}
	AddSequential(new MoveWrist(MoveWrist::open));
	AddSequential(new LiftToHeight(destination));
}
