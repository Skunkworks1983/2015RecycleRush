#include <Commands/Armerino/Arms/Induct.h>

Induct::Induct(float speed) {
	Requires(armIntake);
	this->speed = speed;
	SetTimeout(5.0);
}

Induct::Induct(float speed, double timeout) {
	Requires(armIntake);
	this->speed = speed;
	SetTimeout(timeout);
}

void Induct::Initialize() {

}

void Induct::Execute() {
	armIntake->setGrab(speed);
}

bool Induct::IsFinished() {
	return IsTimedOut();
}

void Induct::End() {
	armIntake->setGrab(0);
}

void Induct::Interrupted() {
	armIntake->setGrab(0);
}
