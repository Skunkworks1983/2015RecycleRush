#include <Commands/AutoCanGrabber/GrabCenterCan.h>
#include <Commands/Automatic/TimedDrive.h>
#include <Commands/Autonomous/Autonomous.h>
#include <Commands/Drivebase/UnrustleGyro.h>
#include <Commands/WaitCommand.h>
#include <Subsystems/AutoCanGrabber.h>

#define MOVE_TO_TOTES_DISTANCE 10
#define MOVE_TO_AUTO_ZONE_DISTANCE 25
#define MOVE_SPEED .4

Autonomous *Autonomous::createGetCenterCan() {
	Autonomous *cmd = new Autonomous("Autonomous-GetCenterCan");
	cmd->AddParallel(new UnrustleGyro());
	cmd->AddParallel(new GrabCenterCan(AutoCanGrabber::GrabberState::GRAB));
	cmd->AddSequential(new TimedDrive(1.000, -MOVE_SPEED));	//TODO: maybe change this? works with 1.0 tho..
	cmd->AddSequential(new TimedDrive(1.350, .7));

	//possibly need to make this happen back and forth multiple times to dislodge the can from mechanism
	cmd->AddSequential(new TimedDrive(1.0, -MOVE_SPEED));
	cmd->AddSequential(new WaitCommand(1.0));
	//cmd->AddSequential(new GrabCenterCan(AutoCanGrabber::GrabberState::RETRACT));
	cmd->AddSequential(new WaitCommand(420.0));
	return cmd;
}
