#include "Pneumatics.h"
#include "../RobotMap.h"
#include "../Commands/UpdateCompressor.h"

Pneumatics::Pneumatics() :
		Subsystem("Pneumatics") {
	SAFE_INIT(COMPRESSOR_PRESSURE_SENSOR_PORT,
			pressureSwitch = new DigitalInput(COMPRESSOR_PRESSURE_SENSOR_PORT););
	LiveWindow::GetInstance()->AddSensor("Pneumatics", "Pressure Switch",
			pressureSwitch);
	SAFE_INIT(COMPRESSOR_RELAY_PORT,
			relay = new Compressor(COMPRESSOR_RELAY_PORT););
	LiveWindow::GetInstance()->AddActuator("Pneumatics", "Compressor", relay);

}

void Pneumatics::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new UpdateCompressor);
}

void Pneumatics::setState(bool state) {
	//relay->Set(state ? Relay::kReverse : Relay::kOff);
	if (state) {
		relay->Start();
	} else {
		relay->Stop();
	}
}

bool Pneumatics::isCompressorOn() {
	return relay->Enabled();
	//return relay->Get() == Relay::kForward;
}

bool Pneumatics::isBelowPressure() {
	return !relay->GetPressureSwitchValue();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
