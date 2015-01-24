#include "Craaaw.h"
#include "../RobotMap.h"
#include "../Commands/MecanumDrive.h"
#include <cmath>

Craaaw::Craaaw(){
	//liftereeno = new LIFT_MOTOR_TYPE(LIFT_MOTOR_CAN);
	canDetected = new DigitalInput(CRAAAW_CAN_DETECTOR);
	craaawLocker = new Solenoid(CRAAAW_TOGGLE);

}

Craaaw::~Craaaw(){
	delete canDetected;
	delete craaawLocker;
}

bool Craaaw::getInput(){
	return canDetected->Get();
}

void Craaaw::Toggle(){
	if(getInput() == true){
		craaawLocker->Set(true);
	}

}



