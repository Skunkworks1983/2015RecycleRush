#include <Commands/Automatic/TimedTurn.h>
#include <Commands/Autonomous/Autonomous.h>
#include <Commands/WaitCommand.h>

Autonomous *Autonomous::createShimmyTest() {
	Autonomous *cmd = new Autonomous("Autonomous-ShimmyTest");
	cmd->AddSequential(new TimedTurn(.5, .4));
	cmd->AddSequential(new TimedTurn(.5, -.4));
	cmd->AddSequential(new TimedTurn(.5, .4));
	cmd->AddSequential(new TimedTurn(.5, -.4));
	cmd->AddSequential(new WaitCommand(30.0));
	return cmd;
}
