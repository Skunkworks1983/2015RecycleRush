#ifndef Autonomous_H
#define Autonomous_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class Autonomous: public CommandGroup
{
public:
	static Autonomous *createJustDrive(float duration, float heading);

	Autonomous();
	Autonomous(char *style);
	virtual void Initialize();
	~Autonomous();
};

#endif
