#include "Score.h"
#include "RobotMap.h"
#include "LiftToHeight.h"
#include "../CanCollecterino/Craaaw/CraaawActuate.h"

Score::Score() {
	AddSequential(new CraaawActuate(DoubleSolenoid::kReverse));
	AddSequential(
			new LiftToHeight(
					CommandBase::toteLifterino->getPID()->GetSetpoint()+SCORE_HEIGHT_CHANGE_AMOUNT_VALUE_INCHES*TOTE_LIFTER_TICKS_PER_INCH));
}
