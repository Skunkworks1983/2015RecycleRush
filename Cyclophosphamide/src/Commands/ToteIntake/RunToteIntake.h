#ifndef TOTE_INTAKE_H
#define TOTE_INTAKE_H

#include "../../CommandBase.h"
#include "WPILib.h"

class RunToteIntake: public CommandBase {
private:
	float speed;
public:
	RunToteIntake(float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
