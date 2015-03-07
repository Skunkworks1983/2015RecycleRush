/*
 * JustDrive.cpp
 *
 *  Created on: Jan 16, 2015
 *      Author: Administrator
 */

#include <Commands/Automatic/SimpleDriveForward.h>
#include <Commands/Automatic/TurnTo.h>
#include <Commands/Autonomous/Autonomous.h>
#include <Commands/CanCollecterino/Arms/MoveArms.h>
#include <Commands/ToteLifting/LiftToHeight.h>
#include <RobotMap.h>
#include <Vision/FollowVision.h>

#define MOVE_FORWARD_TO_NEXT_TOTE 420.0
#define MOVE_TO_AUTO_ZONE_DISTANCE 420.0*3
#define MOVE_BACK_DISTANCE 4.20
#define DRIVE_SPEED .42

Autonomous *Autonomous::createTripleTote() {
	Autonomous *cmd = new Autonomous("Autonomous-TripleTote");
	for (int i = 0; i < 3; i++) {
		cmd->AddSequential(new FollowVision(false));

		cmd->AddSequential(new LiftToHeight(TOTE_LIFTER_FLOOR_HEIGHT));
		cmd->AddSequential(new LiftToHeight(TOTE_LIFTER_LOAD_HEIGHT));
		//cmd->AddSequential(new LiftToHeight(TOTE_LIFTER_FLOOR_HEIGHT));	//TODO: If we have this on the floor, then the camera can't see the next tote

		cmd->AddSequential(new MoveArms(CAN_POT_KNOCK_POSITION));

		cmd->AddSequential(new TurnTo(30));
		cmd->AddSequential(new TurnTo(-60));
		cmd->AddSequential(new TurnTo(30));

		cmd->AddSequential(new FollowVision(false));

		cmd->AddSequential(new LiftToHeight(TOTE_LIFTER_CARRY_HEIGHT));
		if (i < 2) {
			cmd->AddSequential(
					new SimpleDriveForward(MOVE_FORWARD_TO_NEXT_TOTE,
							DRIVE_SPEED));
		}
	}
	cmd->AddSequential(new LiftToHeight(TOTE_LIFTER_CARRY_HEIGHT));
	cmd->AddSequential(new TurnTo(-90));

	cmd->AddSequential(
			new SimpleDriveForward(MOVE_TO_AUTO_ZONE_DISTANCE, DRIVE_SPEED));
	cmd->AddSequential(new LiftToHeight(TOTE_LIFTER_FLOOR_HEIGHT));

	cmd->AddSequential(
			new SimpleDriveForward(-MOVE_BACK_DISTANCE, DRIVE_SPEED));
	return cmd;
}
