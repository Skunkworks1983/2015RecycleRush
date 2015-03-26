#include <Commands/Armerino/Arms/Induct.h>
#include <Commands/Armerino/Arms/MoveArms.h>
#include <Commands/Armerino/Arms/MoveWrist.h>
#include <Commands/Armerino/Craaaw/CraaawActuate.h>
#include <Commands/Armerino/MoveArmsFancy.h>
#include <Commands/Automatic/BestDrive.h>
#include <Commands/Automatic/TurnTo.h>
#include <Commands/Autonomous/Autonomous.h>
#include <Commands/Automatic/SimpleDriveForward.h>
#include <RobotMap.h>

#define SIMPLE_DRIVE_TO_AUTO_DISTANCE 30

Autonomous *Autonomous::createSimpleDriveForward() {
	Autonomous *cmd = new Autonomous("Autonomous-SimpleDriveForward");
	cmd->AddSequential(
			new SimpleDriveForward(SIMPLE_DRIVE_TO_AUTO_DISTANCE, .25));
	return cmd;
}
