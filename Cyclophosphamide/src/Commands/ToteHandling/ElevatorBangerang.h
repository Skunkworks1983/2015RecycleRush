#ifndef Bangerang_H
#define Bangerang_H

#include "../../CommandBase.h"
#include "WPILib.h"

class ElevatorBangerang : public CommandBase
{
private:
	double destination;
	int count;
	bool reachedPosition;
	int speed;

public:
	ElevatorBangerang(double destination);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
