#include <Commands/CanCollecterino/Craaaw/CraaawActuate.h>

CraaawActuate::CraaawActuate(DoubleSolenoid::Value value) {
	Requires(craaaw);
	this->value = value;
	SetTimeout(CRAAAW_TIMEOUT);
}

void CraaawActuate::Initialize() {
	craaaw->setActuated(value);
}

void CraaawActuate::Execute() {

}

bool CraaawActuate::IsFinished() {
	return IsTimedOut();
}

void CraaawActuate::End() {

}

void CraaawActuate::Interrupted() {

}
