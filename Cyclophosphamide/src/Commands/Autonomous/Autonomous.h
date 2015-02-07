#ifndef Autonomous_H
#define Autonomous_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class Autonomous: public CommandGroup
{
public:
	static Autonomous *createDriveDistance(float distance, float heading);
	static Autonomous *createDriveDuration(float duration, float heading);
	static Autonomous *createTurnTo(double targetAngle);
	static Autonomous *createAutoCanerinoPuck();

	Autonomous();
	Autonomous(char *style);
	virtual void Initialize();
	~Autonomous();
};

#endif
