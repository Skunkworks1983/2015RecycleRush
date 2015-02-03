#include "OI.h"
#include "RobotMap.h"
#include "Commands/PushStack/PushPull.h"
#include "Commands/CanCollecterino/CraaawActuate.h"
#include "Commands/CanCollecterino/CraaawUnactuate.h"
#include "Commands/CanCollecterino/LiftArms.h"
#include "Commands/CanCollecterino/LowerArms.h"
#include "Commands/ToteHandling/ToteIntake.h"
#include "Commands/ToteHandling/ToteLifter.h"
#include "Commands/CanCollecterino/Collect.h"
#include "Commands/Automatic/TurnTo.h"

#define SAFE_BUTTON(name, cmd) {if (name!=NULL){cmd;}}

OI::OI()
{
	joystickLeft = new Joystick(OI_JOYSTICK_LEFT);
	joystickRight = new Joystick(OI_JOYSTICK_RIGHT);
	stackButton = new SkunkButt(joystickLeft, OI_JOYSTICK_STACK);
	pushButton = new JoystickButton(joystickRight, OI_JOYSTICKBUTTON_PUSHBUTTON);
	actuateButton = new JoystickButton(joystickRight, OI_JOYSTICKBUTTON_ACTUATEBUTTTON);
	unactuateButton = new JoystickButton(joystickRight, OI_JOYSTICKBUTTON_UNACTUATEBUTTTON);
	liftarmsButton = new JoystickButton(joystickRight, OI_JOYSTICKBUTTON_LIFTARMSBUTTTON);
	lowerarmsButton = new JoystickButton(joystickRight, OI_JOYSTICKBUTTON_LOWERARMSBUTTTON);
	craaawUnactuate = new JoystickButton(joystickLeft, OI_JOYSTICKBUTTON_CRAAAW_UNACTUATE);
	toteintakeButton = new JoystickButton(joystickRight, OI_JOYSTICKBUTTON_TOTEINTAKEBUTTTON);
	totelifterButton = new JoystickButton(joystickRight, OI_JOYSTICKBUTTON_TOTELIFTERBUTTTON);
	motorfowardButton = new JoystickButton(joystickLeft, OI_JOYSTICKBUTTON_MOTORFOWARDBUTTTON);
	motorbackardButton = new JoystickButton(joystickLeft, OI_JOYSTICKBUTTON_MOTORBACKARDBUTTTON);
	wristinButton = new JoystickButton(joystickLeft, OI_JOYSTICKBUTTON_WRISTINBUTTTON);
	wristoutButton =  new JoystickButton(joystickLeft, OI_JOYSTICKBUTTON_WRISTOUTNBUTTTON);
	armsupButton = new JoystickButton(joystickLeft, OI_JOYSTICKBUTTON_ARMSUPBUTTTON);
	armsdownButton = new JoystickButton(joystickLeft, OI_JOYSTICKBUTTON_ARMSDOWNBUTTTON);

	leftLoadButton = new JoystickButton(joystickRight, OI_LOAD_LEFT);
	rightLoadButton = new JoystickButton(joystickRight, OI_LOAD_RIGHT);
}

OI::~OI() {
	delete joystickLeft;
	delete joystickRight;
	delete stackButton;
	delete craaawUnactuate;
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
}

Joystick *OI::getJoystickLeft() {
	return joystickLeft;
}

Joystick *OI::getJoystickRight() {
	return joystickRight;
}
void OI::registerButtonListeners() {
	SAFE_BUTTON(pushButton, pushButton->WhenReleased(new PushPull()));
	SAFE_BUTTON(collectButton, collectButton->WhenPressed(new Collect()));
	SAFE_BUTTON(leftLoadButton, leftLoadButton->WhenReleased(new TurnTo(LOAD_LEFT_ANGLE)));
	SAFE_BUTTON(rightLoadButton, rightLoadButton->WhenReleased(new TurnTo(LOAD_RIGHT_ANGLE)));
}
bool OI::getUnactuate(){
	return craaawUnactuate->Get();
}

bool OI::checkStackFlag() {
	return stackButton->Get();
}
