#include <Commands/Automatic/BestDrive.h>
#include <Commands/Automatic/TurnTo.h>
#include <Commands/Automatic/TurnToThenDrive.h>
#include <Commands/Autonomous/Autonomous.h>
#include <Commands/CanCollecterino/Arms/Induct.h>
#include <Commands/CanCollecterino/Arms/MoveArms.h>
#include <Commands/CanCollecterino/Arms/MoveWrist.h>
#include <Commands/Automatic/SimpleDriveForward.h>
#include <Commands/CanCollecterino/Craaaw/CraaawActuate.h>
#include <Commands/CanCollecterino/MoveArmsFancy.h>
#include <RobotMap.h>

#define START_CAN_DISTANCE_1 30
#define START_CAN_DISTANCE_2 15
#define START_CAN_DISTANCE_3 15
#define START_CAN_DISTANCE_FINAL 4.2
#define START_CAN_ANGLE 50

Autonomous *Autonomous::createStartWithCan() {
	Autonomous *cmd = new Autonomous("Autonomous-StartWithCan");
	cmd->AddSequential(new MoveWrist(MoveWrist::State::close));
	cmd->AddSequential(new MoveArms(CAN_POT_KNOCK_POSITION));
	cmd->AddSequential(new SimpleDriveForward(START_CAN_DISTANCE_1, .25));
	cmd->AddSequential(new MoveWrist(MoveWrist::State::open));
	cmd->AddSequential(new MoveArms(CAN_POT_UP_POSITION));
	cmd->AddSequential(new MoveArmsFancy(MoveArmsFancy::down), 2.0);
	cmd->AddSequential(new Induct(Induct::State::forward, 1.0));
	cmd->AddSequential(new MoveArmsFancy(MoveArmsFancy::up), 2.0);
	cmd->AddSequential(new CraaawActuate(CraaawActuate::close));
	cmd->AddSequential(new MoveWrist(MoveWrist::open));
	cmd->AddSequential(new WaitCommand(30.0));
	return cmd;
}
