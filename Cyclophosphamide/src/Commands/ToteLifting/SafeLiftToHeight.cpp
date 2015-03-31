#include <Commands/Armerino/Arms/MoveWrist.h>
#include <Commands/Armerino/Craaaw/ActuateCanStabilizer.h>
#include <Commands/ToteIntake/RunToteIntake.h>
#include <Commands/ToteLifting/LiftToHeight.h>
#include <Commands/ToteLifting/SafeLiftToHeight.h>
#include <RobotMap.h>

SafeLiftToHeight::SafeLiftToHeight(double destination, bool isCraaawSafe) {
	if (destination == TOTE_LIFTER_LOAD_HEIGHT) {
		AddSequential(new RunToteIntake(TOTE_INTAKE_MOTOR_FULL));
	} else {
		AddSequential(new RunToteIntake(0));
	}
	if (isCraaawSafe) {
		AddSequential(new ActuateCanStabilizer(ActuateCanStabilizer::close));
	}
	AddSequential(new MoveWrist(MoveWrist::open));
	AddSequential(new LiftToHeight(destination));
}
