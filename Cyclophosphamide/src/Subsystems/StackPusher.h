#ifndef StackPusher_H
#define StackPusher_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class StackPusher: public Subsystem
{
private:
	DoubleSolenoid *solenoid;
public:
	enum PushState {
		push = true, pull = false
	};
	StackPusher();
	void InitDefaultCommand();
	void Push();
	void Pull();
	DoubleSolenoid::Value getValue();
};

#endif
