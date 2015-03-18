#include "../RobotMap.h"
#include <Math.h>
#include <Subsystems/ArmIntakerino.h>
#include "../utilities/StallableMotor.h"

ArmIntakerino::ArmIntakerino() :
		Subsystem("CanIntakerino") {
	SAFE_INIT(CAN_MOTOR_GRAB_LEFT_PORT,
			grabMotorLeft = new CAN_MOTOR_TYPE(CAN_MOTOR_GRAB_LEFT_PORT););
	SAFE_INIT(CAN_MOTOR_GRAB_RIGHT_PORT,
			grabMotorRight = new CAN_MOTOR_TYPE(CAN_MOTOR_GRAB_RIGHT_PORT););
}

ArmIntakerino::~ArmIntakerino() {
	delete grabMotorLeft;
	delete grabMotorRight;
}

void ArmIntakerino::setGrab(float value) {
	grabMotorLeft->Set(value);
	grabMotorRight->Set(-value);
}
