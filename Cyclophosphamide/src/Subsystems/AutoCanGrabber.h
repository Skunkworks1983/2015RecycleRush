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
/*
 *
 */
class AutoCanGrabber: public Subsystem {
private:
	DoubleSolenoid *solenoid;
public:
	enum GrabberState{
		GRAB,RETRACT
	};
	AutoCanGrabber();
	virtual ~AutoCanGrabber();
	void actuate(GrabberState state);
};

#endif /* SRC_SUBSYSTEMS_AUTOCANGRABBER_H_ */
