#include <Commands/AutoCanCollecterino/Armerino.h>

Armerino::Armerino(bool up) {
	this->up = up;
}

void Armerino::Initialize() {
	if (up) {
		this->autoCanerinoPuck->armDeploy();
	} else {
		autoCanerinoPuck->armRetract();
	}
	Requires(autoCanerinoPuck);
}

void Armerino::Execute() {

}

bool Armerino::IsFinished() {
	return true;
}

void Armerino::End() {

}

void Armerino::Interrupted() {

}
