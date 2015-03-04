/*
 * JustDrive.cpp
 *
 *  Created on: Jan 16, 2015
 *      Author: Administrator
 */

#include <Commands/Automatic/BestDrive.h>
#include "Autonomous.h"
#include "../Automatic/BestDrive.h"

Autonomous *Autonomous::createDriveDistance(float distance,
		BestDrive::Direction direction) {
	Autonomous *cmd = new Autonomous("Autonomous-DriveDistance");
	cmd->AddSequential(new BestDrive(distance, direction));
	return cmd;
}
