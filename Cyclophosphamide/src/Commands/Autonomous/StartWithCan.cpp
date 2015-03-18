#include <Commands/Autonomous/Autonomous.h>
#include <Commands/Autonomous/GetCan.h>

Autonomous *Autonomous::createStartWithCan() {
	Autonomous *cmd = new Autonomous("Autonomous-StartWithCan");
	cmd->AddSequential(new GetCan());
	return cmd;
}
