/*
 * JustDrive.cpp
 *
 *  Created on: Jan 16, 2015
 *      Author: Administrator
 */

#include <Commands/Automatic/TimedDrive.h>
#include "Autonomous.h"

Autonomous *Autonomous::createDriveDuration(float duration, float speed) {
	Autonomous *cmd = new Autonomous("Autonomous-DriveDuration");
	cmd->AddSequential(new TimedDrive(duration, speed));
	return cmd;
}
