/*
 * PushAutoCanArms.h
 *
 *  Created on: Feb 14, 2015
 *      Author: Administrator
 */
#include "../../CommandBase.h"
#include "../Autonomous/DriveDistance.cpp"

#ifndef SRC_COMMANDS_AUTOCAN_PUSHAUTOCANARMS_H_
#define SRC_COMMANDS_AUTOCAN_PUSHAUTOCANARMS_H_

class AutoCanGrabber: public CommandBase {
private:
	DoubleSolenoid::Value setpoint;
/*
 * Arms on either side of the robot are pushed to a horizontal position from solenoids
 * Puck falls in can
 * Robot drives backwards
 * Two cans are hopefully caught and brought into our side of the field.
 */
public:
	AutoCanGrabber(bool down);
	virtual ~AutoCanGrabber();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_AUTOCAN_PUSHAUTOCANARMS_H_ */
