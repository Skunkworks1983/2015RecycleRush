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

#define SAFE_BUTTON(name, cmd) {if (name!=NULL){cmd;}}

OI::OI()
{
	joystickLeft = new Joystick(OI_JOYSTICK_LEFT);
	joystickRight = new Joystick(OI_JOYSTICK_RIGHT);
	stackButton = new SkunkButt(joystickLeft, OI_JOYSTICK_STACK);
	craaawUnactuate = new JoystickButton(joystickLeft, OI_CRAAAW_UNACTUATE);
	pushButton = new JoystickButton(joystickRight, OI_JOYSTICKBUTTON_PUSHBUTTON);
	actuateButton = new JoystickButton(joystickRight, OI_JOYSTICKBUTTON_ACTUATEBUTTTON);
	unactuateButton = new JoystickButton(joystickRight, OI_JOYSTICKBUTTON_UNACTUATEBUTTTON);
	liftarmsButton = new JoystickButton(joystickRight, OI_JOYSTICKBUTTON_LIFTARMSBUTTTON);
	lowerarmsButton = new JoystickButton(joystickRight, OI_JOYSTICKBUTTON_LOWERARMSBUTTTON);
	toteintakeButton = new JoystickButton(joystickRight, OI_JOYSTICKBUTTON_TOTEINTAKEBUTTTON);
	totelifterButton = new JoystickButton(joystickRight, OI_JOYSTICKBUTTON_TOTELIFTERBUTTTON);
	motorfowardButton = new JoystickButton(joystickLeft, OI_JOYSTICKBUTTON_MOTORFOWARDBUTTTON);
	motorbackardButton = new JoystickButton(joystickLeft, OI_JOYSTICKBUTTON_MOTORBACKARDBUTTTON);
	wristinButton = new JoystickButton(joystickLeft, OI_JOYSTICKBUTTON_WRISTINBUTTTON);
	wristoutButton =  new JoystickButton(joystickLeft, OI_JOYSTICKBUTTON_WRISTOUTNBUTTTON);
	armsupButton = new JoystickButton(joystickLeft, OI_JOYSTICKBUTTON_ARMSUPBUTTTON);
	armsdownButton = new JoystickButton(joystickLeft, OI_JOYSTICKBUTTON_ARMSDOWNBUTTTON);

}

OI::~OI() {
	delete joystickLeft;
	delete joystickRight;
}

Joystick *OI::getJoystickLeft() {
	return joystickLeft;
}

Joystick *OI::getJoystickRight() {
	return joystickRight;
}
void OI::registerButtonListeners() {
	SAFE_BUTTON(pushButton, pushButton->WhenPressed(new PushPull()));
	SAFE_BUTTON(collectButton, collectButton->WhenPressed(new Collect()));
}
bool OI::getUnactuate(){
	return craaawUnactuate->Get();
}

bool OI::checkStackFlag() {
	return stackButton->Get();
}
