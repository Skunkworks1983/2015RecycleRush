#include <Commands/Armerino/Arms/Induct.h>

Induct::Induct(float speed) {
	Requires(armIntakerino);
	this->speed = speed;
	SetTimeout(5.0);
}

Induct::Induct(float speed, double timeout) {
	Requires(armIntakerino);
	this->speed = speed;
	SetTimeout(timeout);
}

void Induct::Initialize() {

}

void Induct::Execute() {
	armIntakerino->setGrab(speed);
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
