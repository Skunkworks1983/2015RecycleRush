#ifndef DriveRight_H
#define DriveRight_H

#include "../../CommandBase.h"
#include "WPILib.h"

class DriveRight: public CommandBase
{
private:
	double distance;
public:
	DriveRight(double distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
