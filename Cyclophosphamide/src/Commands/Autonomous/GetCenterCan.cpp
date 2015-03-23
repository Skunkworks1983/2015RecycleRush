#include <Commands/AutoCanGrabber/GrabCenterCan.h>
#include <Commands/Automatic/SimpleDriveForward.h>
#include <Commands/Autonomous/Autonomous.h>
#include <Subsystems/AutoCanGrabber.h>

#define MOVE_TO_TOTES_DISTANCE 420
#define MOVE_SPEED .75

Autonomous *Autonomous::createGetCenterCan() {
	Autonomous *cmd = new Autonomous("Autonomous-GetCenterCan");
	cmd->AddSequential(
			new SimpleDriveForward(MOVE_TO_TOTES_DISTANCE, MOVE_SPEED));
	cmd->AddSequential(new GrabCenterCan(AutoCanGrabber::GrabberState::GRAB));
	cmd->AddSequential(
			new SimpleDriveForward(-MOVE_TO_TOTES_DISTANCE, MOVE_SPEED));
	//cmd->AddSequential(new WaitCommand(0.5));

	//possibly need to make this happen back and forth multiple times to dislodge the can from mechanism
	cmd->AddSequential(
			new GrabCenterCan(AutoCanGrabber::GrabberState::RETRACT));

	//cmd->AddSequential(new TurnTo(30));	//TODO: maybe?
	//cmd->AddSequential(new GetCan());
	return cmd;
}
