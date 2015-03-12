#include <Commands/CanCollecterino/Craaaw/CraaawActuate.h>

CraaawActuate::CraaawActuate(State value, float timeout) {
	Requires(craaaw);
	this->value = value;
	this->timeout = timeout;
	if (timeout != -1) {
		SetTimeout(timeout);
	}
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
	if (timeout == -1) {
		return true;
	} else {
		return IsTimedOut();
	}
}

void CraaawActuate::End() {

}

void CraaawActuate::Interrupted() {

}
