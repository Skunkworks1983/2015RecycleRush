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

#define SIMPLE_DRIVE_TO_AUTO_DISTANCE 30

Autonomous *Autonomous::createSimpleDriveForward() {
	Autonomous *cmd = new Autonomous("Autonomous-SimpleDriveForward");
	cmd->AddSequential(
			new SimpleDriveForward(SIMPLE_DRIVE_TO_AUTO_DISTANCE, .25));
	return cmd;
}
