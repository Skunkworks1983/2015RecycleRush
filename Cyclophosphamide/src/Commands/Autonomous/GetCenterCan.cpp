#include <Commands/AutoCanGrabber/GrabCenterCan.h>
#include <Commands/Automatic/TimedDrive.h>
#include <Commands/Autonomous/Autonomous.h>
#include <Commands/WaitCommand.h>
#include <Subsystems/AutoCanGrabber.h>

#define MOVE_TO_TOTES_DISTANCE 10
#define MOVE_TO_AUTO_ZONE_DISTANCE 25
#define MOVE_SPEED .4

Autonomous *Autonomous::createGetCenterCan() {
	Autonomous *cmd = new Autonomous("Autonomous-GetCenterCan");
	cmd->AddSequential(
			new TimedDrive(0.5, -MOVE_SPEED));
	cmd->AddSequential(new GrabCenterCan(AutoCanGrabber::GrabberState::GRAB));
	cmd->AddSequential(new WaitCommand(1.0));
	cmd->AddSequential(new TimedDrive(2.5, MOVE_SPEED));

	//possibly need to make this happen back and forth multiple times to dislodge the can from mechanism
	cmd->AddSequential(
			new GrabCenterCan(AutoCanGrabber::GrabberState::RETRACT));
	cmd->AddSequential(new WaitCommand(1.0));
	cmd->AddSequential(new TimedDrive(0.5, -MOVE_SPEED));
	cmd->AddSequential(new WaitCommand(30.0));

	//cmd->AddSequential(new TurnTo(30));	//TODO: maybe?
	//cmd->AddSequential(new GetCan());
	return cmd;
}
