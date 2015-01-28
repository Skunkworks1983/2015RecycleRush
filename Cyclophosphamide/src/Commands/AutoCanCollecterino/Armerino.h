#ifndef ARMERINO_H
#define ARMERINO_H

#include "../../CommandBase.h"
#include "WPILib.h"

class Armerino: public CommandBase
{
private:
	bool up;
public:
	Armerino(bool up);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
