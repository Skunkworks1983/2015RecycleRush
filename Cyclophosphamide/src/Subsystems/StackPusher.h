#ifndef StackPusher_H
#define StackPusher_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

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
