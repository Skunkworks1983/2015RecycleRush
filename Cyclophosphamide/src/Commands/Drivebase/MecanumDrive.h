#ifndef MECANUM_DRIVE_H
#define MECANUM_DRIVE_H

#include "../../CommandBase.h"
#include "WPILib.h"

class MecanumDrive: public CommandBase
{
public:
	MecanumDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
