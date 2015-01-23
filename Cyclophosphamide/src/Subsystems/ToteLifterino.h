#ifndef Craterino_H
#define Craterino_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 * This is the crate lifter
 */
class ToteLifterino: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	ToteLifterino();
	void InitDefaultCommand();


};

#endif
