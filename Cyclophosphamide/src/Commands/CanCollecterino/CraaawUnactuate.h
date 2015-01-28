#ifndef CraaawUnactuate_H
#define CraaawUnactuate_H

#include "../../CommandBase.h"
#include "WPILib.h"

class CraaawUnactuate: public CommandBase
{
public:
	CraaawUnactuate();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
