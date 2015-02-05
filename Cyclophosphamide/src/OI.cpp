#include <Commands/ToteHandling/LiftToHeight.h>
#include "OI.h"
#include "RobotMap.h"
#include "Commands/PushStack/PushPull.h"
#include "Commands/CanCollecterino/CraaawActuate.h"
#include "Commands/CanCollecterino/CraaawUnactuate.h"
#include "Commands/CanCollecterino/LiftArms.h"
#include "Commands/CanCollecterino/LowerArms.h"
#include "Commands/ToteHandling/ToteIntake.h"
#include "Commands/CanCollecterino/Collect.h"
#include "Commands/Automatic/TurnTo.h"
#include "Commands/Automatic/BetterDrive.h"

#define SAFE_BUTTON(name, cmd) {if (name!=NULL){cmd;}}

OI::OI()
{
	joystickLeft = new Joystick(OI_JOYSTICK_LEFT);
	joystickRight = new Joystick(OI_JOYSTICK_RIGHT);
	/*
	stackButton = new SkunkButt(joystickLeft, OI_JOYSTICK_STACK);
	pushButton = new JoystickButton(joystickRight, OI_JOYSTICKBUTTON_PUSHBUTTON);
	actuateButton = new JoystickButton(joystickRight, OI_JOYSTICKBUTTON_ACTUATEBUTTON);
	unactuateButton = new JoystickButton(joystickRight, OI_JOYSTICKBUTTON_UNACTUATEBUTTON);
	liftarmsButton = new JoystickButton(joystickRight, OI_JOYSTICKBUTTON_LIFTARMSBUTTON);
	lowerarmsButton = new JoystickButton(joystickRight, OI_JOYSTICKBUTTON_LOWERARMSBUTTON);
	toteintakeButton = new JoystickButton(joystickRight, OI_JOYSTICKBUTTON_TOTEINTAKEBUTTON);
	totelifterButton = new JoystickButton(joystickRight, OI_JOYSTICKBUTTON_TOTELIFTERBUTTON);
	motorfowardButton = new JoystickButton(joystickLeft, OI_JOYSTICKBUTTON_MOTORFOWARDBUTTON);
	motorbackwardButton = new JoystickButton(joystickLeft, OI_JOYSTICKBUTTON_MOTORBACKWARDBUTTON);
	wristinButton = new JoystickButton(joystickLeft, OI_JOYSTICKBUTTON_WRISTINBUTTON);
	wristoutButton =  new JoystickButton(joystickLeft, OI_JOYSTICKBUTTON_WRISTOUTNBUTTON);
	armsupButton = new JoystickButton(joystickLeft, OI_JOYSTICKBUTTON_ARMSUPBUTTON);
	armsdownButton = new JoystickButton(joystickLeft, OI_JOYSTICKBUTTON_ARMSDOWNBUTTON);
	leftLoadButton = new JoystickButton(joystickRight, OI_LOAD_LEFT);
	rightLoadButton = new JoystickButton(joystickRight, OI_LOAD_RIGHT);
	*/
}

OI::~OI() {
	delete joystickLeft;
	delete joystickRight;
	/*
	delete stackButton;
	delete pushButton;
	delete actuateButton;
	delete liftarmsButton;
	delete toteintakeButton;
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
void OI::registerButtonListeners() {
	/*
	SAFE_BUTTON(pushButton, pushButton->WhenReleased(new PushPull()));
	SAFE_BUTTON(collectButton, collectButton->WhenPressed(new Collect()));
	SAFE_BUTTON(actuateButton, actuateButton->WhenPressed(new CraaawActuate()));
	SAFE_BUTTON(unactuateButton, unactuateButton->WhenPressed(new CraaawUnactuate()));
	SAFE_BUTTON(liftarmsButton, liftarmsButton->WhenPressed(new LiftArms()));
	SAFE_BUTTON(lowerarmsButton, lowerarmsButton->WhenPressed(new LowerArms()));
	SAFE_BUTTON(toteintakeButton, toteintakeButton->WhenPressed(new ToteIntake()));
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

bool OI::getUnactuate(){
	return unactuateButton->Get();
}

bool OI::checkStackFlag() {
	return stackButton->Get();
}
