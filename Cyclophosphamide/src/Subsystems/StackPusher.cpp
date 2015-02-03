#include "StackPusher.h"
#include "../RobotMap.h"
#include "../Commands/PushStack/PushPull.h"

StackPusher::StackPusher() :
		Subsystem("StackPusher") {
	SAFE_INIT(PUSHER_RIGHT, solenoid = new DoubleSolenoid(PUSHER_RIGHT, PUSHER_LEFT););
}


void StackPusher::Push(){
	solenoid->Set(DoubleSolenoid::kReverse);
}
void StackPusher::Pull(){
	solenoid->Set(DoubleSolenoid::kForward);
}

void StackPusher::InitDefaultCommand()
{
	// SetDefaultCommand (new PushPull);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
