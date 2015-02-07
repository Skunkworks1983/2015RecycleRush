#include <Commands/CanCollecterino/Arms/Induct.h>

Induct::Induct() {
}

void Induct::Initialize() {
	canCollecterino->setGrab(CAN_GRAB_SPEED);
	Requires(canCollecterino);
}

void Induct::Execute() {

}

bool Induct::IsFinished() {
	return canCollecterino->getCanSensor();
}

void Induct::End() {
	canCollecterino->setGrab(0);
}

void Induct::Interrupted() {

}
