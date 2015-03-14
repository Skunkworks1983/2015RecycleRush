#include <Commands/Automatic/SimpleDriveForward.h>
#include <Commands/Automatic/TurnTo.h>
#include <Commands/Autonomous/Autonomous.h>
#include <Commands/Autonomous/GetCan.h>
#include <Commands/WaitCommand.h>
#include <SmartDashboard/SmartDashboard.h>

Autonomous *Autonomous::createStartWithCan() {
	Autonomous *cmd = new Autonomous("Autonomous-StartWithCan");
	cmd->AddSequential(new GetCan());
	return cmd;
}
