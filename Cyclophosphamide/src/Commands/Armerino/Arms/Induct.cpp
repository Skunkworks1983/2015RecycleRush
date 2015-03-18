#include <Commands/Armerino/Arms/Induct.h>

Induct::Induct(State state, Mode mode) {
	Requires(armIntakerino);
	this->state = state;
	this->mode = mode;
	SetTimeout(5.0);
}

Induct::Induct(State state, double timeout, Mode mode) {
	Requires(armIntakerino);
	this->state = state;
	this->mode = mode;
	SetTimeout(timeout);
}

void Induct::Initialize() {

}

void Induct::Execute() {
	switch (state) {
	case forward:
		armIntakerino->setGrab(CAN_GRAB_SPEED);
		break;
	case reverse:
		if (mode == tote) {
			armIntakerino->setGrab(TOTE_EXPEL_SPEED);
		}
		else {
			armIntakerino->setGrab(-CAN_GRAB_SPEED);
		}
		break;
	case stopped:
		armIntakerino->setGrab(0);
		break;
	}
}

bool Induct::IsFinished() {
	return IsTimedOut();
}

void Induct::End() {
	armIntakerino->setGrab(0);
}

void Induct::Interrupted() {
	armIntakerino->setGrab(0);
}
