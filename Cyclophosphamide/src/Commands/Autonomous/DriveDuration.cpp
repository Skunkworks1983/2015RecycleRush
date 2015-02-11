/*
 * JustDrive.cpp
 *
 *  Created on: Jan 16, 2015
 *      Author: Administrator
 */

#include <Commands/Automatic/TimedDrive.h>
#include "Autonomous.h"

Autonomous *Autonomous::createDriveDuration(float duration, float heading) {
	Autonomous *cmd = new Autonomous("Autonomous-DriveDuration");
	cmd->AddSequential(new TimedDrive(duration, heading));
	return cmd;
}
