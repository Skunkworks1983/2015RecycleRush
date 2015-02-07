/*
 * JustDrive.cpp
 *
 *  Created on: Jan 16, 2015
 *      Author: Administrator
 */

#include "Autonomous.h"
#include "../Automatic/BetterDrive.h"

Autonomous *Autonomous::createDriveDistance(float distance, float heading) {
	Autonomous *cmd = new Autonomous("Autonomous-DriveDistance");
	cmd->AddSequential(new BetterDrive(distance, heading));
	return cmd;
}
