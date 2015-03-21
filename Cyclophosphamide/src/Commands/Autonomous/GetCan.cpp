#include <Commands/Armerino/Arms/Induct.h>
#include <Commands/Armerino/Arms/MoveArms.h>
#include <Commands/Armerino/Arms/MoveWrist.h>
#include <Commands/Armerino/CanToCraaawTransfer.h>
#include <Commands/Armerino/MoveArmsFancy.h>
#include <Commands/Automatic/SimpleDriveForward.h>
#include <Commands/Autonomous/GetCan.h>
#include <Commands/WaitCommand.h>
#include <RobotMap.h>
#include <SmartDashboard/SmartDashboard.h>

#define START_CAN_DISTANCE_1 30

GetCan::GetCan() {
	AddSequential(new MoveWrist(MoveWrist::State::close));
	AddSequential(new MoveArms(CAN_POT_KNOCK_POSITION));
	AddSequential(new SimpleDriveForward(START_CAN_DISTANCE_1, .25));
	AddSequential(new MoveWrist(MoveWrist::State::open));
	AddSequential(new MoveArms(CAN_POT_UP_POSITION));
	AddSequential(new MoveArmsFancy(MoveArmsFancy::down), 2.0);
	AddSequential(new MoveWrist(MoveWrist::State::close));
	AddSequential(new Induct(CAN_GRAB_SPEED, 1.0));
	AddSequential(new MoveArmsFancy(MoveArmsFancy::up), 2.0);
	AddParallel(new CanToCraaawTransfer());
	AddSequential(new WaitCommand(1.0));
}
