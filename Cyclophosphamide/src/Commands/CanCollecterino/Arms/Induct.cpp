#include <Commands/CanCollecterino/Arms/Induct.h>

Induct::Induct(State state) {
	Requires(canIntakerino);
	this->state = state;
}

void Induct::Initialize() {
	switch(state){
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

void Induct::Execute() {

}

bool Induct::IsFinished() {
	return true;
}

void Induct::End() {
	canIntakerino->setGrab(0);
}

void Induct::Interrupted() {
	canIntakerino->setGrab(0);
}
