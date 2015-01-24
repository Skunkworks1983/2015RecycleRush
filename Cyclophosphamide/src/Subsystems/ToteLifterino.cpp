#include <Subsystems/ToteLifterino.h>
#include "../RobotMap.h"

ToteLifterino::ToteLifterino() :
		Subsystem("ToteLifterino")
{
//	lift_traveled_sensor = new DigitalInput(TOTE_LIFTER_SENSOR);
	RightLifter = new Talon(TOTE_LIFTER_RIGHT);
	LeftLifter = new Talon(TOTE_LIFTER_LEFT);
	positionEncoder = new Encoder(TOTE_LIFTER_ENCODER_CA,
			TOTE_LIFTER_ENCODER_CB,
			TOTE_LIFTER_ENCODER_REVERSED);
}

void ToteLifterino::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

//int ToteLifterino::getStackerPosition() {
//	int val = positionEncoder->Get();
//	if (closeEnough(val, TOTE_LIFTER_VAL_POS_0)) {
//		return TOTE_LIFTER_KEY_POS_0;
//	} else if (closeEnough(val, TOTE_LIFTER_VAL_POS_1)) {
//		return TOTE_LIFTER_KEY_POS_1;
//	} else if (closeEnough(val, TOTE_LIFTER_VAL_POS_2)) {
//		return TOTE_LIFTER_KEY_POS_2;
//	} else if (closeEnough(val, TOTE_LIFTER_VAL_POS_3)) {
//		return TOTE_LIFTER_KEY_POS_3;
//	} else {
//		return TOTE_LIFTER_KEY_POS_MOTION;
//	}
//}

int ToteLifterino::getStackerPosition() {
	if (isAtDestination()) {
		return destination;
	} else {
		return TOTE_LIFTER_KEY_POS_MOTION;
	}
}

bool ToteLifterino::closeEnough(int value, int constant) {
	return ((value >= constant - TOTE_LIFTER_ENCODER_DEADBAND) && (value <= constant + TOTE_LIFTER_ENCODER_DEADBAND));
}

void ToteLifterino::setDestination(int position) {
	if (position != destination) {
		at_destination = false;
	}
	destination = position;
}

bool ToteLifterino::isAtDestination() {
	return at_destination;
}
