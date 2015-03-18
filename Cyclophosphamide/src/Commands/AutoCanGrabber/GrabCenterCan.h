/*
 * GrabCenterCan.h
 *
 *  Created on: Mar 18, 2015
 *      Author: S-4020395
 */

#ifndef SRC_COMMANDS_AUTOCANGRABBER_GRABCENTERCAN_H_
#define SRC_COMMANDS_AUTOCANGRABBER_GRABCENTERCAN_H_

#include <CommandBase.h>

/*
 *
 */
class GrabCenterCan: public CommandBase {
private:
	AutoCanGrabber::GrabberState state;
public:
	GrabCenterCan(AutoCanGrabber::GrabberState state);
	virtual ~GrabCenterCan();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_AUTOCANGRABBER_GRABCENTERCAN_H_ */
