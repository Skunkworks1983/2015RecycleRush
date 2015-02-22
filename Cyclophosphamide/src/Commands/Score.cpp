#include "Score.h"
#include "RobotMap.h"
#include "ToteHandling/LiftRelative.h"
#include "CanCollecterino/Craaaw/CraaawActuate.h"

Score::Score() {
	AddSequential(new CraaawActuate(DoubleSolenoid::kReverse));
	AddSequential(new LiftRelative(SCORE_HEIGHT_CHANGE_AMOUNT_VALUE_INCHES));
}
