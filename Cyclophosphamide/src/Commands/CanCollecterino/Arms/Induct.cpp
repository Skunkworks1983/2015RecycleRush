#include <Commands/CanCollecterino/Arms/Induct.h>

Induct::Induct() {
	kek = 0;
}

Induct::Induct(State state, double timeout) {
	Requires(canIntakerino);
	this->state = state;
	SetTimeout(timeout);
}

void Induct::Initialize() {

}

void Induct::Execute() {
	switch (state) {
	case forward:
		canIntakerino->setGrab(CAN_GRAB_SPEED);
		break;
	case reverse:
		canIntakerino->setGrab(-CAN_GRAB_SPEED);
		break;
	case stopped:
		canIntakerino->setGrab(0);
		break;
	}
}

bool Induct::IsFinished() {
	return IsTimedOut();
}

void Induct::End() {
	canIntakerino->setGrab(0);
}

void Induct::Interrupted() {
	canIntakerino->setGrab(0);
}
