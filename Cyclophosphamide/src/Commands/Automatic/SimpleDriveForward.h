#ifndef SimpleDriveForward_H
#define SimpleDriveForward_H

#include <CommandBase.h>

class SimpleDriveForward: public CommandBase {
private:
	float targetTicks;
	double speed, startingPos, timeout = -420, signedSpeed;
public:
	SimpleDriveForward(float target, double speed);
	SimpleDriveForward(float targetInch, double speed, double timeout);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
