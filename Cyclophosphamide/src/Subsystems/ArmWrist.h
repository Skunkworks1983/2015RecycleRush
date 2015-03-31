#ifndef CanWristerino_H
#define CanWristerino_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
/**
 * Subsystem composed of two solenoids for clamping the recycling can for pickup.
 * Needed to be separate for requires conflicts.
 */
class ArmWrist: public Subsystem {
private:
	DoubleSolenoid *wrists;
	bool toggleWrist;
public:
	ArmWrist();
	~ArmWrist();
	void InitDefaultCommand();

	void setWrist(DoubleSolenoid::Value value);

	bool getWristToggle();
	void doTheToggleWrist();
};

#endif
