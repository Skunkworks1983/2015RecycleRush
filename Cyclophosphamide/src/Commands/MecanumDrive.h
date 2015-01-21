#ifndef MecanumDrive_H
#define MecanumDrive_H

#include "../CommandBase.h"
#include "WPILib.h"

class MecanumDrive: public CommandBase
{
private:
	bool firstIteration;
public:
	MecanumDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
