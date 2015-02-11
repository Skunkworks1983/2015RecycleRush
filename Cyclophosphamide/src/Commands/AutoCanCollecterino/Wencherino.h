#ifndef WINCHERINO_H
#define WINCHERINO_H

#include "../../CommandBase.h"
#include "WPILib.h"

class Wencherino: public CommandBase
{
private:
	AutoCanerinoPuck value;
	double setPoint;
	bool pull;

public:
	Wencherino(AutoCanerinoPuck::WenchSetting wenchSetting);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
