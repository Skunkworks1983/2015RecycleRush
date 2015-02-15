/*
 * LiftToHeightVelocity.h
 *
 *  Created on: Feb 11, 2015
 *      Author: S-4020395
 */

#ifndef SRC_COMMANDS_TOTEHANDLING_LIFTTOHEIGHTVELOCITY_H_
#define SRC_COMMANDS_TOTEHANDLING_LIFTTOHEIGHTVELOCITY_H_

#include "WPILib.h"
#include "../../CommandBase.h"

/*
 *
 */
class LiftToHeightVelocity: public CommandBase {
private:
	double speed;
public:
	LiftToHeightVelocity(double speed);
	virtual ~LiftToHeightVelocity();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_TOTEHANDLING_LIFTTOHEIGHTVELOCITY_H_ */
