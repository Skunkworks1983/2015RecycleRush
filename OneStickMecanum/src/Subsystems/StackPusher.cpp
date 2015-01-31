#include "StackPusher.h"
#include "../RobotMap.h"
#include "../Commands/PushStack/PushStack.h"

StackPusher::StackPusher() :
		Subsystem("StackPusher")
{
	right = new Solenoid(0, PUSHER_RIGHT);
	left = new Solenoid (0, PUSHER_LEFT);
}

void StackPusher::Push(){
	right->Set(true);
	left->Set(true);
}
void StackPusher::Pull(){
	right->Set(false) ;
	left->Set(false);
}
void StackPusher::InitDefaultCommand()
{
	//SetDefaultCommand (new PushStack);// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
