#include "AnalogRangeIOButton.h"
#include "DriverStation.h"

AnalogRangeIOButton::AnalogRangeIOButton(int joystickPort,
		Joystick::AxisType axis, double lowThreshold, double highThreshold) {
	this->port = joystickPort;
	this->axis = axis;
	this->lowThreshold = lowThreshold;
	this->highThreshold = highThreshold;
}

AnalogRangeIOButton::~AnalogRangeIOButton() {
	// twiddle our thumbs
}

bool AnalogRangeIOButton::Get() {
	double volts = DriverStation::GetInstance()->GetStickAxis(port, axis);
	return volts >= lowThreshold && volts <= highThreshold;
}
