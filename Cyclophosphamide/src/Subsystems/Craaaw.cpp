#include "Craaaw.h"
#include "../RobotMap.h"
#include "../Commands/MecanumDrive.h"
#include <cmath>
#include "../Commands/CanCollecterino/CraaawActuate.h"

Craaaw::Craaaw(): Subsystem("Craaaw"){
	//liftereeno = new LIFT_MOTOR_TYPE(LIFT_MOTOR_CAN);
	canDetected = new DigitalInput(CRAAAW_CAN_DETECTOR);
	craaawLocker = new Solenoid(CRAAAW_TOGGLE);
}

Craaaw::~Craaaw(){
	delete canDetected;
	delete craaawLocker;

}

void Craaaw::InitDefaultCommand(){
	SetDefaultCommand(new CraaawActuate());
}

bool Craaaw::getInput(){
	return canDetected->Get();
}

void Craaaw::toggle(){
	if(getInput() == true){
		craaawLocker->Set(true);
	}

}



