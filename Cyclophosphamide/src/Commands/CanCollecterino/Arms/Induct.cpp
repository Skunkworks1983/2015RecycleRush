#include <Commands/CanCollecterino/Arms/Induct.h>

Induct::Induct() {
	fuck = 0;
	Requires(canCollecterino);
}

void Induct::Initialize() {
	canCollecterino->setGrab(CAN_GRAB_SPEED);
}

void Induct::Execute() {

}

bool Induct::IsFinished() {
	canCollecterino->StallDiag();
	return canCollecterino->getCanSensor();
}

void Induct::End() {
	canCollecterino->setGrab(0);
}

void Induct::Interrupted() {
	canCollecterino->setGrab(0);
}
