#ifndef Craaaw_H
#define Craaaw_H
#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
#include "RobotMap.h"
#include "GyroDriver/IMU.h"
class Craaaw: public Subsystem {
private:
	DoubleSolenoid *craaawLocker;
	bool isActuated;
public:
	Craaaw();
	~Craaaw();
	void setActuated(DoubleSolenoid::Value value);
	bool isOpen();
};
#endif
