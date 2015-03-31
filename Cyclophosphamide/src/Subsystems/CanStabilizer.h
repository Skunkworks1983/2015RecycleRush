#ifndef Craaaw_H
#define Craaaw_H

#include <Commands/Subsystem.h>
#include <DoubleSolenoid.h>

/**
 * pneumatics, both motor set value and air pressure goes forward either true of false?
 */
class CanStabilizer: public Subsystem {
private:
	DoubleSolenoid *craaawLocker;
	bool isActuated;
public:
	CanStabilizer();
	~CanStabilizer();
	void setActuated(DoubleSolenoid::Value value);
	bool isOpen();
};
#endif
