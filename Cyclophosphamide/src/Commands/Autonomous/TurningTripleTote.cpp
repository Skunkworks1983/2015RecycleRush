/*
 * JustDrive.cpp
 *
 *  Created on: Jan 16, 2015
 *      Author: Administrator
 */

#include <Commands/Automatic/BestDrive.h>
#include <Commands/Automatic/TurnTo.h>
#include <Commands/Autonomous/Autonomous.h>
#include <Commands/CanCollecterino/Arms/MoveArms.h>
#include <Commands/ToteLifting/LiftToHeight.h>
#include <RobotMap.h>

Autonomous *Autonomous::createTurningTripleTote() {
	Autonomous *cmd = new Autonomous("Autonomous-TurningTripleTote");
	cmd->AddSequential(new LiftToHeight(TOTE_LIFTER_FLOOR_HEIGHT));
//	cmd->AddSequential(new ToteIntake(ToteIntake::forward));
//	cmd->AddSequential(new ToteIntake(ToteIntake::stopped));
	cmd->AddSequential(new TurnTo(-45));
	cmd->AddSequential(new MoveArms(false));
	cmd->AddSequential(new TurnTo(-90));
	cmd->AddSequential(new MoveArms(true));
	cmd->AddSequential(new BestDrive(33, BestDrive::forward));
	cmd->AddSequential(new LiftToHeight(TOTE_LIFTER_FLOOR_HEIGHT));
//	cmd->AddSequential(new ToteIntake(ToteIntake::forward));
//	cmd->AddSequential(new ToteIntake(ToteIntake::stopped));
	cmd->AddSequential(new TurnTo(-45));
	cmd->AddSequential(new MoveArms(false));
	cmd->AddSequential(new TurnTo(-90));
	cmd->AddSequential(new MoveArms(true));
	cmd->AddSequential(new BestDrive(33, BestDrive::forward));
	cmd->AddSequential(new LiftToHeight(TOTE_LIFTER_FLOOR_HEIGHT));
//	cmd->AddSequential(new ToteIntake(ToteIntake::forward));
//	cmd->AddSequential(new ToteIntake(ToteIntake::stopped));
	cmd->AddSequential(new BestDrive(107, BestDrive::right));
	return cmd;
}
