#include <CANTalon.h>
#include <Subsystems/ArmIntake.h>

ArmIntake::ArmIntake() :
		Subsystem("CanIntakerino") {
	SAFE_INIT(CAN_MOTOR_GRAB_LEFT_PORT,
			grabMotorLeft = new CAN_MOTOR_TYPE(CAN_MOTOR_GRAB_LEFT_PORT););
	SAFE_INIT(CAN_MOTOR_GRAB_RIGHT_PORT,
			grabMotorRight = new CAN_MOTOR_TYPE(CAN_MOTOR_GRAB_RIGHT_PORT););
}

ArmIntake::~ArmIntake() {
	delete grabMotorLeft;
	delete grabMotorRight;
}

void ArmIntake::setGrab(float value) {
	grabMotorLeft->Set(value);
	grabMotorRight->Set(-value);
}

CAN_MOTOR_TYPE *ArmIntake::getRight() {
	return grabMotorRight;
}

CAN_MOTOR_TYPE *ArmIntake::getLeft() {
	return grabMotorLeft;
}

