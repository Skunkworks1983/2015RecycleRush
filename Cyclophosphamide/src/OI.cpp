#include <Commands/Automatic/BestDrive.h>
#include <Commands/CanCollecterino/Arms/MoveArms.h>
#include <Commands/ToteHandling/LiftToHeight.h>
#include "OI.h"
#include "RobotMap.h"
#include "Commands/PushStack/PushStack.h"
#include "Commands/CanCollecterino/Craaaw/CraaawActuate.h"
#include "Commands/CanCollecterino/Craaaw/CraaawUnactuate.h"
#include "Commands/CanCollecterino/Arms/MoveArms.h"
#include "Commands/CanCollecterino/Arms/Induct.h"
#include "Commands/ToteHandling/ToteIntake.h"
#include "Commands/CanCollecterino/Collect.h"
#include "Commands/Automatic/TurnTo.h"
#include "Commands/ToteHandling/LiftToHeightVelocity.h"
#include "Commands/ToteHandling/LiftToHeight.h"
#define SAFE_BUTTON(name, cmd) {if (name!=NULL){cmd;}}

OI::OI() {
	joystickLeft = new Joystick(OI_JOYSTICK_LEFT);
	joystickRight = new Joystick(OI_JOYSTICK_RIGHT);
	/*
	 pushButton = new JoystickButton(joystickRight,
	 OI_JOYSTICKBUTTON_PUSHBUTTON);
	 actuateButton = new JoystickButton(joystickRight,
	 OI_JOYSTICKBUTTON_ACTUATEBUTTON);
	 unactuateButton = new JoystickButton(joystickRight,
	 OI_JOYSTICKBUTTON_UNACTUATEBUTTON);
	 liftarmsButton = new JoystickButton(joystickRight,
	 OI_JOYSTICKBUTTON_LIFTARMSBUTTON);
	 lowerarmsButton = new JoystickButton(joystickRight,
	 OI_JOYSTICKBUTTON_LOWERARMSBUTTON);
	 */
	toteIntakeButtonForward = new JoystickButton(joystickLeft,
	OI_JOYSTICKBUTTON_TOTEINTAKE_BUTTON_FORWARD);
	toteIntakeButtonReverse = new JoystickButton(joystickLeft,
	OI_JOYSTICKBUTTON_TOTEINTAKE_BUTTON_REVERSE);
	/*
	 totelifterButton = new JoystickButton(joystickRight,
	 OI_JOYSTICKBUTTON_TOTELIFTERBUTTON);
	 motorfowardButton = new JoystickButton(joystickLeft,
	 OI_JOYSTICKBUTTON_MOTORFOWARDBUTTON);
	 motorbackwardButton = new JoystickButton(joystickLeft,
	 OI_JOYSTICKBUTTON_MOTORBACKWARDBUTTON);
	 wristinButton = new JoystickButton(joystickLeft,
	 OI_JOYSTICKBUTTON_WRISTINBUTTON);
	 wristoutButton = new JoystickButton(joystickLeft,
	 OI_JOYSTICKBUTTON_WRISTOUTNBUTTON);
	 armsupButton = new JoystickButton(joystickLeft,
	 OI_JOYSTICKBUTTON_ARMSUPBUTTON);
	 armsdownButton = new JoystickButton(joystickLeft,
	 OI_JOYSTICKBUTTON_ARMSDOWNBUTTON);
	 leftLoadButton = new JoystickButton(joystickRight, OI_LOAD_LEFT);
	 rightLoadButton = new JoystickButton(joystickRight, OI_LOAD_RIGHT);
	 */

	toteLifterUp = new JoystickButton(joystickLeft, 6);
	toteLifterDown = new JoystickButton(joystickLeft, 4);
	runPIDElevator = new JoystickButton(joystickLeft, 7);
}

OI::~OI() {
	delete joystickLeft;
	delete joystickRight;
	/*
	 delete goToHighElevator;
	 delete goToMidElevator;
	 delete goToLowElevator;

	 delete pushButton;
	 delete actuateButton;
	 delete liftarmsButton;
	 */
	delete toteIntakeButtonForward;
	delete toteIntakeButtonReverse;
	delete runPIDElevator;
	/*
	 delete totelifterButton;
	 delete wristinButton;
	 delete wristoutButton;
	 delete armsupButton;
	 delete armsdownButton;
	 delete leftLoadButton;
	 delete rightLoadButton;
	 */
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
	SAFE_BUTTON(pushButton,
			pushButton->WhenReleased(new PushStack(StackPusher::push, 1.0f)));
	SAFE_BUTTON(pullButton,
			pullButton->WhenReleased(new PushStack(StackPusher::pull, 1.0f)));

	SAFE_BUTTON(toteLifterDown,
			toteLifterDown->WhileHeld(new LiftToHeightVelocity(-.5)));
	SAFE_BUTTON(toteLifterUp,
			toteLifterUp->WhileHeld(new LiftToHeightVelocity(.5)));
	SAFE_BUTTON(runPIDElevator, runPIDElevator->WhenPressed(new LiftToHeight(1100)));
	/*
	 SAFE_BUTTON(collectButton, collectButton->WhenPressed(new Collect()));
	 SAFE_BUTTON(actuateButton, actuateButton->WhenPressed(new CraaawActuate()));
	 SAFE_BUTTON(unactuateButton, unactuateButton->WhenPressed(new CraaawUnactuate()));
	 SAFE_BUTTON(liftarmsButton, liftarmsButton->WhenPressed(new LiftArms()));
	 SAFE_BUTTON(lowerarmsButton, lowerarmsButton->WhenPressed(new LowerArms()));
	 */

//	SAFE_BUTTON(toteIntakeButtonForward,
//			toteIntakeButtonForward->WhenPressed(
//					new ToteIntake(ToteIntake::forward)));
//	SAFE_BUTTON(toteIntakeButtonReverse,
//			toteIntakeButtonReverse->WhenPressed(
//					new ToteIntake(ToteIntake::reverse)));
	SAFE_BUTTON(toteIntakeButtonReverse,
			toteIntakeButtonReverse->WhenReleased(new MoveArms(true)));
	SAFE_BUTTON(toteIntakeButtonForward,
			toteIntakeButtonForward->WhenPressed(new MoveArms(false)));

	SAFE_BUTTON(toteIntakeButtonForward,
			toteIntakeButtonForward->WhenPressed(new MoveArms(false)));
	/*
	 SAFE_BUTTON(totelifterButton, totelifterButton->WhenPressed(new LiftToHeight(0)));
	 SAFE_BUTTON(motorfowardButton, motorfowardButton->WhenPressed(new Collect()));
	 SAFE_BUTTON(motorbackwardButton,motorbackwardButton->WhenPressed(new BetterDrive(10000, 0)));
	 SAFE_BUTTON(wristinButton,wristinButton->WhenPressed(new Collect()));
	 SAFE_BUTTON(wristoutButton,wristoutButton->WhenPressed(new Collect()));
	 SAFE_BUTTON(armsupButton,armsupButton->WhenPressed(new Collect()));
	 SAFE_BUTTON(armsdownButton,armsdownButton->WhenPressed(new Collect()));
	 SAFE_BUTTON(leftLoadButton, leftLoadButton->WhenReleased(new TurnTo(LOAD_LEFT_ANGLE)));
	 SAFE_BUTTON(rightLoadButton, rightLoadButton->WhenReleased(new TurnTo(LOAD_RIGHT_ANGLE)));
	 */
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

bool OI::getUnactuate() {
	return unactuateButton->Get();
}
