#include <Commands/CanCollecterino/Craaaw/CraaawActuate.h>

CraaawActuate::CraaawActuate(DoubleSolenoid::Value value) {
	Requires(craaaw);
	this->value = value;
}

void CraaawActuate::Initialize() {
	craaaw->setActuated(value);
}

void CraaawActuate::Execute() {

}

bool CraaawActuate::IsFinished() {
	return true;
}

void CraaawActuate::End() {

}

void CraaawActuate::Interrupted() {

}
