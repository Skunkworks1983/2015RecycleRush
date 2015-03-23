/*
 * RampInduct.h
 *
 *  Created on: Mar 21, 2015
 *      Author: s-4020395
 */

#ifndef SRC_COMMANDS_ARMERINO_ARMS_RAMPINDUCT_H_
#define SRC_COMMANDS_ARMERINO_ARMS_RAMPINDUCT_H_

#include <CommandBase.h>

/*
 *
 */
class RampInduct: public CommandBase {
private:
	float maxSpeed;
	double startTime, currentTime, time;
	bool isRamped;
public:
	RampInduct(float maxSpeed, double time);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_ARMERINO_ARMS_RAMPINDUCT_H_ */
