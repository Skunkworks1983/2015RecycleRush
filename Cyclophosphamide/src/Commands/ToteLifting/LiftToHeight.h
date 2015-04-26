#ifndef ToteLifter_H
#define ToteLifter_H

#include "../../CommandBase.h"
#include "WPILib.h"

class LiftToHeight: public CommandBase {
private:
	double destination, initial;
	int count;
public:
	LiftToHeight(double destination);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
