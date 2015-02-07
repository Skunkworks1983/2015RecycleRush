/*
 * JustDrive.cpp
 *
 *  Created on: Jan 16, 2015
 *      Author: Administrator
 */

#include "Autonomous.h"
#include "../Automatic/AutoDrive.h"

Autonomous *Autonomous::createDriveDuration(float duration, float heading) {
	Autonomous *cmd = new Autonomous("Autonomous-DriveDuration");
	cmd->AddSequential(new AutoDrive(duration, heading));
	return cmd;
}
