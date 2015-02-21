#include <Commands/Automatic/BestDrive.h>
#include <Commands/CanCollecterino/Arms/MoveArms.h>
#include <Commands/ToteHandling/LiftToHeight.h>
#include "OI.h"
#include "RobotMap.h"
#include "Commands/PushStack/PushStack.h"
#include "Commands/CanCollecterino/Craaaw/CraaawActuate.h"
#include "Commands/CanCollecterino/CanToCraaawTransfer.h"
#include "Commands/CanCollecterino/Arms/MoveArms.h"
#include "Commands/CanCollecterino/Arms/Induct.h"
#include "Commands/ToteHandling/ToteIntake.h"
#include "Commands/CanCollecterino/Collect.h"
#include "Commands/Automatic/TurnToThenDrive.h"
#include "Commands/ToteHandling/LiftToHeightVelocity.h"
#include "Commands/ToteHandling/LiftToHeight.h"
#include "Commands/ToteHandling/DownUp.h"
#include "Commands/CanCollecterino/Arms/MoveWrist.h"
#include "Commands/CanCollecterino/MoveArmsAndCollect.h"
#include "Commands/ToteHandling/ToggleCoop.h"
#include "Commands/ToteHandling/ElevatorBangerang.h"

#define SAFE_BUTTON(name, cmd) {if (name!=NULL){cmd;}}

OI::OI() {
	// TODO driver trigger to middle position
	// TODO co-op mode

	joystickLeft = new Joystick(0);
	joystickRight = new Joystick(1);
	joystickOperator = new Joystick(2);

	toteIntake = new JoystickButton(joystickOperator, 14);
	stackThenLoadPos = new JoystickButton(joystickOperator, 13);
	stackThenCarryPos = new JoystickButton(joystickOperator, 12);
	toteLifterFloor = new JoystickButton(joystickOperator, 420);
	toteLifterCarry = new JoystickButton(joystickOperator, 11);
	toteLifterLift = new JoystickButton(joystickOperator, 8);
	toteLifterThirdPos = new JoystickButton(joystickOperator, 422);
	pushSwitch = new JoystickButton(joystickOperator, 7);
	wrist = new JoystickButton(joystickOperator, 2);
	wristToggle = new JoystickButton(joystickOperator, 9);
	canCollector = new JoystickButton(joystickOperator, 1);
	//collect = new JoystickButton(joystickOperator, 1);
	canCollectFwd = new JoystickButton(joystickOperator, 4);
	canCollectRvs = new JoystickButton(joystickOperator, 3);
	toggleCoop = new JoystickButton(joystickOperator, 6);
	score = new JoystickButton(joystickOperator, 5);

	leftLoadButton = new JoystickButton(joystickRight, 5);
	rightLoadButton = new JoystickButton(joystickRight, 6);
	moveArmsWhackMode = new JoystickButton(joystickRight, 1);
}

OI::~OI() {
	delete joystickLeft;
	delete joystickRight;
	delete joystickOperator;
	delete pushSwitch;
	delete toteIntake;
	delete toteLifterFloor;
	delete toteLifterCarry;
	delete toteLifterLift;
	delete toteLifterThirdPos;
	delete moveArmsWhackMode;
	delete leftLoadButton;
	delete rightLoadButton;
	delete stackThenCarryPos;
	delete stackThenLoadPos;
	delete canCollector;
	delete collect;
	delete canCollectFwd;
	delete canCollectRvs;
	delete wrist;
	delete wristToggle;
	delete armsToggle;
	delete toggleCoop;
	delete score;
}

Joystick *OI::getJoystickOperator() {
	return joystickOperator;
}

Joystick *OI::getJoystickLeft() {
	return joystickLeft;
}

Joystick *OI::getJoystickRight() {
	return joystickRight;
}

double OI::getAnalogValue(int input) {
	//find input at port %input%
	//return analog value for that device
	return 0.0;
}

void OI::registerButtonListeners() {
	// Can manipulation
	SAFE_BUTTON(canCollector,
			canCollector->WhenPressed(new MoveArmsAndCollect(true)));
	SAFE_BUTTON(canCollector,
			canCollector->WhenReleased(new MoveArmsAndCollect(false)));
	SAFE_BUTTON(wristToggle,
			wristToggle->WhenPressed(new MoveWrist(MoveWrist::toggle)));

	// Loading/stacking
	SAFE_BUTTON(toteIntake,
			toteIntake->WhenPressed(new ToteIntake(ToteIntake::forward)));
	SAFE_BUTTON(toteIntake,
			toteIntake->WhenReleased(new ToteIntake(ToteIntake::stopped)));
	SAFE_BUTTON(stackThenLoadPos,
			stackThenLoadPos->WhenPressed(new DownUp(DownUp::load)));
	SAFE_BUTTON(stackThenCarryPos,
			stackThenCarryPos->WhenPressed(new DownUp(DownUp::carry)));
	SAFE_BUTTON(toggleCoop, toggleCoop->WhenPressed(new ToggleCoop()));
	SAFE_BUTTON(score,
			score->WhenPressed(new LiftToHeight(CommandBase::toteLifterino->getPID()->GetSetpoint()+SCORE_HEIGHT_CHANGE_AMOUNT_VALUE_INCHES*TOTE_LIFTER_TICKS_PER_INCH)));

	// Scoring

	SAFE_BUTTON(toteLifterFloor,
			toteLifterFloor->WhenReleased(new LiftToHeight(TOTE_LIFTER_FLOOR_HEIGHT)));
	SAFE_BUTTON(toteLifterCarry,
			toteLifterCarry->WhenReleased(new LiftToHeight(TOTE_LIFTER_CARRY_HEIGHT)));
	SAFE_BUTTON(toteLifterLift,
			toteLifterLift->WhenReleased(new LiftToHeight(TOTE_LIFTER_STACK_HEIGHT)));

	SAFE_BUTTON(toteLifterThirdPos,
			toteLifterThirdPos->WhenReleased(new LiftToHeight(TOTE_LIFTER_STACK_HEIGHT)));

	// Stack delivery slides
	SAFE_BUTTON(pushSwitch,
			pushSwitch->WhenPressed(new PushStack(StackPusher::push, 1.0f)));
	SAFE_BUTTON(pushSwitch,
			pushSwitch->WhenReleased(new PushStack(StackPusher::pull, 1.0f)));

	// Overrides
	SAFE_BUTTON(wrist, wrist->WhenPressed(new MoveWrist(MoveWrist::open)));
	SAFE_BUTTON(wrist, wrist->WhenReleased(new MoveWrist(MoveWrist::close)));
	SAFE_BUTTON(canCollectFwd,
			canCollectFwd->WhenPressed(new Induct(Induct::forward)));
	SAFE_BUTTON(canCollectFwd,
			canCollectFwd->WhenReleased(new Induct(Induct::stopped)));
	SAFE_BUTTON(canCollectRvs,
			canCollectRvs->WhenPressed(new Induct(Induct::reverse)));
	SAFE_BUTTON(canCollectRvs,
			canCollectRvs->WhenReleased(new Induct(Induct::stopped)));

	// Special driver buttons
	SAFE_BUTTON(leftLoadButton,
			leftLoadButton->WhenReleased(new TurnToThenDrive(LOAD_LEFT_ANGLE)));
	SAFE_BUTTON(rightLoadButton,
			rightLoadButton->WhenReleased(new TurnToThenDrive(LOAD_RIGHT_ANGLE)));
	SAFE_BUTTON(moveArmsWhackMode,
			moveArmsWhackMode->WhenPressed(new MoveArms(CAN_POT_KNOCK_POSITION)));

	// Old stuff
//	SAFE_BUTTON(toteLifterDown,
//			toteLifterDown->WhileHeld(new LiftToHeightVelocity(-.5)));
//	SAFE_BUTTON(toteLifterUp,
//			toteLifterUp->WhileHeld(new LiftToHeightVelocity(.5)));
}

bool OI::isJoystickButtonPressed(bool isLeft, int val) {
	if (isLeft) {
		return val > 0 && val < joystickLeft->GetButtonCount()
				&& joystickLeft->GetRawButton(val);
	} else {
		return val > 0 && val < joystickRight->GetButtonCount()
				&& joystickRight->GetRawButton(val);
	}
}
