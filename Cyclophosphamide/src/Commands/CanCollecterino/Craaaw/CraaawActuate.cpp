#include <Commands/CanCollecterino/Craaaw/CraaawActuate.h>

CraaawActuate::CraaawActuate(State value) {
	Requires(craaaw);
	this->value = value;
	SetTimeout(CRAAAW_TIMEOUT);
}

void CraaawActuate::Initialize() {
	DoubleSolenoid::Value theRealValue;
	switch (value) {
	case CraaawActuate::open:
		theRealValue = DoubleSolenoid::Value::kReverse;
		break;
	case CraaawActuate::close:
		theRealValue = DoubleSolenoid::Value::kForward;
		break;
	case CraaawActuate::toggle:
		theRealValue =
				craaaw->isOpen() ?
						DoubleSolenoid::Value::kReverse :
						DoubleSolenoid::Value::kForward;
		break;
	}
	craaaw->setActuated(theRealValue);
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
