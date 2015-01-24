#ifndef StackPusher_H
#define StackPusher_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class StackPusher: public Subsystem
{
private:
	Solenoid *right;
	Solenoid *left;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	StackPusher();
	void InitDefaultCommand();
	void Push();
	void Pull();
};

#endif
