#include "LowerArms.h"

LowerArms::LowerArms() {

}

void LowerArms::Initialize() {
	canCollecterino->brakeArms(false);
	canCollecterino->moveDownPosition();
	Requires(canCollecterino);
}

void LowerArms::Execute() {

}

bool LowerArms::IsFinished() {
	return canCollecterino->getPotValue() <= CAN_POT_UP_POSITION;
}

void LowerArms::End() {
	canCollecterino->brakeArms(true);
}

void LowerArms::Interrupted() {

}
