#include <Subsystems/CanIntakerino.h>
#include "../RobotMap.h"
#include <Math.h>
#include "../utilities/StallableMotor.h"

CanIntakerino::CanIntakerino() :
		Subsystem("CanIntakerino") {
	SAFE_INIT(CAN_MOTOR_GRAB_LEFT_PORT,
			grabMotorLeft = new CAN_MOTOR_TYPE(CAN_MOTOR_GRAB_LEFT_PORT););
	SAFE_INIT(CAN_MOTOR_GRAB_RIGHT_PORT,
			grabMotorRight = new CAN_MOTOR_TYPE(CAN_MOTOR_GRAB_RIGHT_PORT););
}

CanIntakerino::~CanIntakerino() {
	delete grabMotorLeft;
	delete grabMotorRight;
}

void CanIntakerino::setGrab(float value) {
	grabMotorLeft->Set(value);
	grabMotorLeft->Set(-value);
}
