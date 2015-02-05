#ifndef BetterDrive_H
#define BetterDrive_H

#include "../../CommandBase.h"
#include "WPILib.h"

class BetterDrive: public CommandBase
{
private:
	float targetDistance;
	float distanceRemain;
	double targetAngle;
	DriveBae::EncoderZero* billy;
public:
	BetterDrive(float distance, double angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();


};

#endif
