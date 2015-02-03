#include "StackPusher.h"
#include "../RobotMap.h"
#include "../Commands/PushStack/PushStack.h"

StackPusher::StackPusher() :
		Subsystem("ExampleSubsystem") {
	SAFE_INIT(PUSHER_RIGHT, right = new DoubleSolenoid(PUSHER_RIGHT, PUSHER_LEFT););
}

void StackPusher::Push() {
	right->Set(DoubleSolenoid::kForward);
}
void StackPusher::Pull() {
	right->Set(DoubleSolenoid::kReverse);
}
void StackPusher::InitDefaultCommand() {
	//SetDefaultCommand (new PushStack);// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
