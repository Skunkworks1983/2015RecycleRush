/*
 * RampInduct.h
 *
 *  Created on: Mar 21, 2015
 *      Author: s-4020395
 */

#ifndef SRC_COMMANDS_ARMERINO_ARMS_RAMPTIMEDDRIVE_H_
#define SRC_COMMANDS_ARMERINO_ARMS_RAMPTIMEDDRIVE_H_

#include <CommandBase.h>

/*
 *
 */
class RampTimedDrive: public CommandBase {
private:
	float desiredSpeed;
	double startTime, currentTime, time,value;
	bool isRamped;
public:
	RampTimedDrive(float maxSpeed, double time);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_ARMERINO_ARMS_RAMPINDUCT_H_ */
