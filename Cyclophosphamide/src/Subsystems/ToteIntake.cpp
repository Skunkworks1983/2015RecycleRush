#include <CANTalon.h>
#include <Commands/ToteIntake/RunToteIntake.h>
#include <Encoder.h>
#include <RobotMap.h>
#include <Subsystems/ToteIntake.h>

#define TOTE_INTAKE_P 0.5
#define TOTE_INTAKE_I 0.0
#define TOTE_INTAKE_D 0.0

ToteIntake::ToteIntake() :
		Subsystem("ToteIntakerino") {
	SAFE_INIT(TOTE_INTAKE_MOTOR_PORT_OLD,
			toteIntakeMotor = new CANTalon(TOTE_INTAKE_MOTOR_PORT_OLD););
	encoder = new Encoder(TOTE_INTAKE_ENCODER_PORT);
	encoder->SetDistancePerPulse(1 / TOTE_INTAKE_ENCODER_TICKS_PER_REV);
}

ToteIntake::~ToteIntake() {
	delete encoder;
	delete toteIntakeMotor;
}

void ToteIntake::InitDefaultCommand() {
	//SetDefaultCommand(new ToteIntake(TOTE_INTAKE_RPM));
}

double ToteIntake::getRPM() {
	return encoder->GetRate(); /// TOTE_INTAKE_ENCODER_TICKS_PER_REV / 60.0;
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void ToteIntake::setMotor(float speed) {
	toteIntakeMotor->Set(speed);
}

Encoder *ToteIntake::getEncoder() {
	return encoder;
}
