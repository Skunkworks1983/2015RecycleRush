#ifndef INDUCTERINO_H
#define INDUCTERINO_H

#include "../../../CommandBase.h"
#include "WPILib.h"

class Induct: public CommandBase
{
private:
	int fuck;
public:
	Induct();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
