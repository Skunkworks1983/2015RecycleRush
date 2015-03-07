#ifndef CanWristerino_H
#define CanWristerino_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class CanWristerino: public Subsystem {
private:
	DoubleSolenoid *wrists;
	bool toggleWrist;
public:
	CanWristerino();
	~CanWristerino();
	void InitDefaultCommand();

	void setWrist(DoubleSolenoid::Value value);

	bool getWristToggle();
	void doTheToggleWrist();
};

#endif
