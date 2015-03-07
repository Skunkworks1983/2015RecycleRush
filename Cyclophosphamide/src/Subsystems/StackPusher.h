#ifndef StackPusher_H
#define StackPusher_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
/**
 *pneumatics
 * Stack Pusher pull in, or push out using the stick that hold to the totes to unload totes.
 */

class StackPusher: public Subsystem {
public:
	enum PushState {
		push, pull, toggle
	};
private:
	DoubleSolenoid *solenoid;
	PushState state;
public:
	StackPusher();
	void InitDefaultCommand();
	void Push();
	void Pull();
	DoubleSolenoid::Value getValue();
	PushState getState();
};

#endif
