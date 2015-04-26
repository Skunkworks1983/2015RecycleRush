#include <Commands/AutoCanGrabber/GrabCenterCan.h>
#include <Commands/Automatic/NoRotateTimedDrive.h>
#include <Commands/Automatic/TimedDrive.h>
#include <Commands/Autonomous/Autonomous.h>
#include <Commands/WaitCommand.h>
#include <Subsystems/AutoCanGrabber.h>

#define MOVE_TO_TOTES_DISTANCE 10
#define MOVE_TO_AUTO_ZONE_DISTANCE 25
#define MOVE_SPEED .4

Autonomous *Autonomous::createSuperAuto() {
	Autonomous *cmd = new Autonomous("Autonomous-SuperAuto");
	cmd->AddSequential(new WaitCommand(.75));
	cmd->AddSequential(new TimedDrive(.88, 1.0));
	// above used to be 1.35, .7

	cmd->AddSequential(new WaitCommand(420.0));
	return cmd;
}
