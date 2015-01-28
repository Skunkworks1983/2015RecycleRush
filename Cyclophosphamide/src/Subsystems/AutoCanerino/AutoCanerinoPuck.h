#ifndef AUTO_COLLECTERINO_ARMS_H
#define AUTO_COLLECTERINO_ARMS_H

#include "WPILib.h"
#include "../../RobotMap.h"

class AutoCanerinoPuck: public Subsystem
{
private:
	DoubleSolenoid *armActuate;
	AUTO_CAN_MOTOR_TYPE *wench;
	AnalogInput *wenchPot;

public:
	enum WinchSetting {
		letDown,
		bringIn,
		putBack
	};

	AutoCanerinoPuck();
	~AutoCanerinoPuck();
	void armDeploy();
	void armRetract();
	void wenchSet(bool pull);
	void wenchStop();
	double wenchGetPosition();
};

#endif
