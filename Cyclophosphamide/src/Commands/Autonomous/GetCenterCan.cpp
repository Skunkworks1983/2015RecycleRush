#include <Commands/AutoCanGrabber/GrabCenterCan.h>
#include <Commands/Automatic/TurnTo.h>
#include <Commands/Autonomous/Autonomous.h>
#include <Commands/Autonomous/GetCan.h>
#include <Commands/WaitCommand.h>
#include <Subsystems/AutoCanGrabber.h>

Autonomous *Autonomous::createGetCenterCan() {
	Autonomous *cmd = new Autonomous("Autonomous-GetCenterCan");
	cmd->AddSequential(new GrabCenterCan(AutoCanGrabber::GrabberState::GRAB));
	cmd->AddSequential(new WaitCommand(0.5));
	cmd->AddSequential(
			new GrabCenterCan(AutoCanGrabber::GrabberState::RETRACT));
	cmd->AddSequential(new TurnTo(30));
	cmd->AddSequential(new GetCan());
	return cmd;
}
