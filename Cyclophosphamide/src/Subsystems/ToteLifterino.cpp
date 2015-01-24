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
	destinations = vector<int>();
}

void ToteLifterino::InitDefaultCommand()
{
	SetDefaultCommand(new tote_lifter());
}

bool ToteLifterino::closeEnough(int value, int constant) {
	return ((value >= constant - TOTE_LIFTER_ENCODER_DEADBAND) && (value <= constant + TOTE_LIFTER_ENCODER_DEADBAND));
}

void ToteLifterino::addDestination(int destination) {
	destinations.push_back(destination);
}

bool ToteLifterino::At(int position) {
	int constant = getValue(position);

	return closeEnough(positionEncoder->Get(), constant);
}

int ToteLifterino::getValue(int key) {
	switch (key) {
	case TOTE_LIFTER_KEY_POS_0:
		return TOTE_LIFTER_VAL_POS_0;
	case TOTE_LIFTER_KEY_POS_1:
		return TOTE_LIFTER_VAL_POS_1;
	case TOTE_LIFTER_KEY_POS_2:
		return TOTE_LIFTER_VAL_POS_2;
	case TOTE_LIFTER_KEY_POS_3:
		return TOTE_LIFTER_VAL_POS_3;
	}
}

void ToteLifterino::checkAtDestination() {
	if (At(destinations[0])) {
		destinations.erase(destinations.begin());
	}
}

void ToteLifterino::driveTowardsDestination() {
	checkAtDestination();

	if (destinations.size() > 0) { // if there are new destinations
		int myPosition = positionEncoder->Get();
		if (myPosition < getValue(destinations[0])) {
			RightLifter->Set(TOTE_LIFTER_UP_SPEED);
			LeftLifter->Set(TOTE_LIFTER_UP_SPEED);
		} else {
			RightLifter->Set(TOTE_LIFTER_DOWN_SPEED);
			LeftLifter->Set(TOTE_LIFTER_DOWN_SPEED);
		}
	}
}
