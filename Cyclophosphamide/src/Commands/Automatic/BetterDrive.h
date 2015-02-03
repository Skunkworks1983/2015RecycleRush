#ifndef BetterDrive_H
#define BetterDrive_H

#include "../../CommandBase.h"
#include "WPILib.h"

class BetterDrive: public CommandBase
{
private:
	float targetDistance;
	float distanceRemain;
	float initialPos;
public:
	BetterDrive(float distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();


};

#endif
