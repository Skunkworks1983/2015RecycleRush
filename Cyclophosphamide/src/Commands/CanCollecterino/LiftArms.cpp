#include "LiftArms.h"

LiftArms::LiftArms() {

}

void LiftArms::Initialize() {
	canCollecterino->brakeArms(false);
	canCollecterino->moveUpPosition();
	Requires(canCollecterino);
}

void LiftArms::Execute() {

}

bool LiftArms::IsFinished() {
	return canCollecterino->getPotValue() >= CAN_POT_UP_POSITION;
}

void LiftArms::End() {
	canCollecterino->brakeArms(true);
}

void LiftArms::Interrupted() {

}
