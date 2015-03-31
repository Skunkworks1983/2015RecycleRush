#include <Commands/Automatic/GetCan.h>
#include <Commands/Autonomous/Autonomous.h>

Autonomous *Autonomous::createStartWithCan() {
	Autonomous *cmd = new Autonomous("Autonomous-StartWithCan");
	cmd->AddSequential(new GetCan());
	return cmd;
}
