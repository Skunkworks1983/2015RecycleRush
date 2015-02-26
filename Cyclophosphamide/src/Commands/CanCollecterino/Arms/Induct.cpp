#include <Commands/CanCollecterino/Arms/Induct.h>

Induct::Induct() {
	kek = 0;
	Requires(canIntakerino);
}

void Induct::Initialize() {
	canIntakerino->setGrab(CAN_GRAB_SPEED);
}

void Induct::Execute() {

}

bool Induct::IsFinished() {
	return false;
}

void Induct::End() {
	canIntakerino->setGrab(0);
}

void Induct::Interrupted() {
	canIntakerino->setGrab(0);
}
