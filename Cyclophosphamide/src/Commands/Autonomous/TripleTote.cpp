/*
 * JustDrive.cpp
 *
 *  Created on: Jan 16, 2015
 *      Author: Administrator
 */

#include <Commands/Automatic/BestDrive.h>
#include "Autonomous.h"
#include "../Automatic/BestDrive.h"
#include "../ToteHandling/LiftToHeight.h"
#include "../ToteHandling/ToteIntake.h"
#include "../PushStack/PushPull.h"

Autonomous *Autonomous::createTripleTote() {
	Autonomous *cmd = new Autonomous("Autonomous-TripleTote");
	cmd->AddSequential(new LiftToHeight(TOTE_LIFTER_FLOOR_HEIGHT));
	cmd->AddSequential(new ToteIntake(ToteIntake::forward));
	cmd->AddSequential(new ToteIntake(ToteIntake::stopped));
	cmd->AddSequential(new BestDrive(45, BestDrive::backward));
	cmd->AddSequential(new BestDrive(33, BestDrive::left));
	cmd->AddSequential(new LiftToHeight(TOTE_LIFTER_FLOOR_HEIGHT));
	cmd->AddSequential(new ToteIntake(ToteIntake::forward));
	cmd->AddSequential(new ToteIntake(ToteIntake::stopped));
	cmd->AddSequential(new BestDrive(45, BestDrive::backward));
	cmd->AddSequential(new BestDrive(33, BestDrive::left));
	cmd->AddSequential(new LiftToHeight(TOTE_LIFTER_FLOOR_HEIGHT));
	cmd->AddSequential(new ToteIntake(ToteIntake::forward));
	cmd->AddSequential(new ToteIntake(ToteIntake::stopped));
	cmd->AddSequential(new BestDrive(107, BestDrive::backward));
	cmd->AddSequential(new LiftToHeight(TOTE_LIFTER_FLOOR_HEIGHT));
	cmd->AddSequential(new PushPull());
	return cmd;
}
