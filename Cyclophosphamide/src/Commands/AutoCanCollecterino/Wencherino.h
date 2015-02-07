#ifndef WINCHERINO_H
#define WINCHERINO_H

#include "../../CommandBase.h"
#include "WPILib.h"

class Wincherino: public CommandBase
{
private:
	AutoCanerinoPuck value;
	double setPoint;
	bool pull;

public:
	Wincherino(AutoCanerinoPuck::WinchSetting winchSetting);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
