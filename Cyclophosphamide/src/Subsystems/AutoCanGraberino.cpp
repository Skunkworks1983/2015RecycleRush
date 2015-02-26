#include <Subsystems/AutoCanGraberino.h>
#include "../RobotMap.h"
#include "../Commands/AutoCan/AutoCanGrabber.h"

AutoCanGraberino::AutoCanGraberino() :
		Subsystem("AutoCanGraberino") {
/*	SAFE_INIT(PUSHER_RIGHT_PORT, solenoid = new DoubleSolenoid(COMPRESSOR_RELAY_PORT, PUSHER_RIGHT_PORT, PUSHER_LEFT_PORT););
	state = up;*/
}

AutoCanGraberino::~AutoCanGraberino() {

}

void AutoCanGraberino::InitDefaultCommand() {

}

void AutoCanGraberino::Up(){

}

void AutoCanGraberino::Down(){

}

DoubleSolenoid::Value AutoCanGraberino::getValue() {
	return solenoid->Get();
}

/*void AutoPuckerino::setSolenoid(){

}

void AutoPuckerino::setMotor(float speed){
	wench = speed;
}

Encoder AutoPuckerino::getEnc(){
	return encoder;
}*/
