#include <Commands/Automatic/BestDrive.h>
#include <Commands/Automatic/TurnTo.h>
#include <Commands/Automatic/TurnToThenDrive.h>
#include <Commands/Autonomous/Autonomous.h>
#include <Commands/CanCollecterino/Arms/Induct.h>
#include <Commands/CanCollecterino/Arms/MoveArms.h>
#include <Commands/CanCollecterino/Arms/MoveWrist.h>
#include <RobotMap.h>

#define START_CAN_DISTANCE_1 420
#define START_CAN_DISTANCE_2 42
#define START_CAN_DISTANCE_3 420
#define START_CAN_DISTANCE_FINAL 4.2
#define START_CAN_INDUCT_TIMEOUT 4200
#define START_CAN_ANGLE 30

Autonomous *Autonomous::createStartWithCan() {
	Autonomous *cmd = new Autonomous("Autonomous-StartWithCan");
	cmd->AddSequential(new MoveArms(CAN_POT_KNOCK_POSITION));
	cmd->AddSequential(
			new BestDrive(START_CAN_DISTANCE_1, BestDrive::Direction::forward));
	cmd->AddSequential(new TurnTo(START_CAN_ANGLE));
	cmd->AddSequential(
			new BestDrive(START_CAN_DISTANCE_2, BestDrive::Direction::forward));
	cmd->AddSequential(new MoveWrist(true));
	cmd->AddParallel(new Induct(), START_CAN_INDUCT_TIMEOUT);
	cmd->AddSequential(
			new BestDrive(START_CAN_DISTANCE_3,
					BestDrive::Direction::backward));
	cmd->AddParallel(new MoveArms(CAN_POT_UP_POSITION));
	cmd->AddSequential(new TurnToThenDrive(LOAD_LEFT_ANGLE));
	cmd->AddSequential(
			new BestDrive(START_CAN_DISTANCE_FINAL,
					BestDrive::Direction::backward));
	return cmd;
}
