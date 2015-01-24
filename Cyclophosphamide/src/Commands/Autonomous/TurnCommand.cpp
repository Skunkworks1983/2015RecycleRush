/*
 * JustDrive.cpp
 *
 *  Created on: Jan 16, 2015
 *      Author: Administrator
 */

#include <Commands/Automatic/TurnTo.h>
#include "Autonomous.h"

Autonomous *Autonomous::createTurnTo(double targetAngle) {
	Autonomous *cmd = new Autonomous("Autonomous-TurnCommand");
	cmd->AddSequential(new TurnTo(targetAngle));
	return cmd;
}
