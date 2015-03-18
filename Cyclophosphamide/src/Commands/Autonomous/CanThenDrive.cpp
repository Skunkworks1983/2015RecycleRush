#include <Commands/Automatic/SimpleDriveForward.h>
#include <Commands/Automatic/TurnTo.h>
#include <Commands/Autonomous/Autonomous.h>
#include <Commands/Autonomous/GetCan.h>
#include <Commands/WaitCommand.h>

#define BOT_TO_AUTO_ZONE_DIST 30

Autonomous *Autonomous::createStartWithCanThenDrive() {
	Autonomous *cmd = new Autonomous("Autonomous-CanThenDrive");
	cmd->AddSequential(new GetCan());
	cmd->AddParallel(new TurnTo(135));
	cmd->AddSequential(new WaitCommand(1.0));
	cmd->AddSequential(new SimpleDriveForward(BOT_TO_AUTO_ZONE_DIST, .25));
	cmd->AddSequential(new WaitCommand(30.0));
	return cmd;
}
