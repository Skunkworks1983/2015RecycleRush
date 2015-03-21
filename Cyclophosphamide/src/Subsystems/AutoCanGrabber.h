/*
 * AutoCanGrabber.h
 *
 *  Created on: Mar 18, 2015
 *      Author: S-4020395
 */

#ifndef SRC_SUBSYSTEMS_AUTOCANGRABBER_H_
#define SRC_SUBSYSTEMS_AUTOCANGRABBER_H_

#include <Commands/Subsystem.h>
#include "wpilib.h"
#include <robotmap.h>
/*auto can graber is pneumatics (double solenoid)
 *using switch statement if to grab, air pressure go forward if retract then reverse.
 */
class AutoCanGrabber: public Subsystem {
public:
	enum GrabberState {
		GRAB, RETRACT, TOGGLE
	};
private:
	DoubleSolenoid *solenoid;
	bool grabLast;
public:
	AutoCanGrabber();
	virtual ~AutoCanGrabber();
	void actuate(GrabberState state);
};

#endif /* SRC_SUBSYSTEMS_AUTOCANGRABBER_H_ */
