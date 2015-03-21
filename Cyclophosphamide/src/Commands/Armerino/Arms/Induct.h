#ifndef INDUCTERINO_H
#define INDUCTERINO_H

#include "../../../CommandBase.h"
#include "WPILib.h"

class Induct: public CommandBase {
private:
	float speed;
public:
	Induct(float speed);
	Induct(float speed, double timeout);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
