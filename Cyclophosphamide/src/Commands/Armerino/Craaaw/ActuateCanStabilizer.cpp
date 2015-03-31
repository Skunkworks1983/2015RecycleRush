#include <Commands/Armerino/Craaaw/ActuateCanStabilizer.h>

ActuateCanStabilizer::ActuateCanStabilizer(State value, float timeout) {
	Requires(canStabilizer);
	this->value = value;
	this->timeout = timeout;
	if (timeout != -1) {
		SetTimeout(timeout);
	}
}

void ActuateCanStabilizer::Initialize() {
	DoubleSolenoid::Value theRealValue;
	switch (value) {
	case ActuateCanStabilizer::open:
		theRealValue = DoubleSolenoid::Value::kReverse;
		break;
	case ActuateCanStabilizer::close:
		theRealValue = DoubleSolenoid::Value::kForward;
		break;
	case ActuateCanStabilizer::toggle:
		theRealValue =
				canStabilizer->isOpen() ?
						DoubleSolenoid::Value::kReverse :
						DoubleSolenoid::Value::kForward;
		break;
	}
	canStabilizer->setActuated(theRealValue);
}

void ActuateCanStabilizer::Execute() {

}

bool ActuateCanStabilizer::IsFinished() {
	if (timeout == -1) {
		return true;
	} else {
		return IsTimedOut();
	}
}

void ActuateCanStabilizer::End() {

}

void ActuateCanStabilizer::Interrupted() {

}
