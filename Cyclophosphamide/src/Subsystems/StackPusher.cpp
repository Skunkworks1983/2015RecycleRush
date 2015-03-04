#include "StackPusher.h"
#include "../RobotMap.h"

StackPusher::StackPusher() :
		Subsystem("StackPusher") {
	SAFE_INIT(PUSHER_RIGHT_PORT,
			solenoid = new DoubleSolenoid(COMPRESSOR_RELAY_PORT, PUSHER_RIGHT_PORT, PUSHER_LEFT_PORT););
	state = pull;
}

void StackPusher::Push() {
	solenoid->Set(DoubleSolenoid::kReverse);
	state = push;
}

void StackPusher::Pull() {
	solenoid->Set(DoubleSolenoid::kForward);
	state = pull;
}

StackPusher::PushState StackPusher::getState() {
	return state;
}

DoubleSolenoid::Value StackPusher::getValue() {
	return solenoid->Get();
}

void StackPusher::InitDefaultCommand() {
	// SetDefaultCommand (new PushPull);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
