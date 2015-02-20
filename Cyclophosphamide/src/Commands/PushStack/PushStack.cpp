#include "PushStack.h"

PushStack::PushStack(StackPusher::PushState state, float timeout) {
	Requires(stackPusher);
	this->state = state;
	SetTimeout(timeout);
}

// Called just before this Command runs the first time
void PushStack::Initialize() {
	switch (state) {
	case StackPusher::pull:
		stackPusher->Pull();
		break;
	case StackPusher::push:
		stackPusher->Push();
		break;
	case StackPusher::toggle:
		switch (stackPusher->getState()) {
		case StackPusher::pull:
			stackPusher->Push();
			break;
		case StackPusher::push:
			stackPusher->Pull();
			break;
		}
		break;
	};
}

// Called repeatedly when this Command is scheduled to run
void PushStack::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool PushStack::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void PushStack::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PushStack::Interrupted() {

}
