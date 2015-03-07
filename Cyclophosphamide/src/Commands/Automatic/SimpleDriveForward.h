#ifndef SimpleDriveForward_H
#define SimpleDriveForward_H

#include <CommandBase.h>

class SimpleDriveForward: public CommandBase {
private:
	float targetTicks;
	double speed, startingPos;
public:
	SimpleDriveForward(float target, double speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
