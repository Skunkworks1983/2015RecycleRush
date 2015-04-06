/*
 * NoRotateTimedDrive.h
 *
 *  Created on: Apr 4, 2015
 *      Author: S-4020395
 */

#ifndef SRC_COMMANDS_AUTOMATIC_NOROTATETIMEDDRIVE_H_
#define SRC_COMMANDS_AUTOMATIC_NOROTATETIMEDDRIVE_H_

#include <CommandBase.h>

/*
 *
 */
class NoRotateTimedDrive: public CommandBase {
private:
	float time, speed;
public:
	NoRotateTimedDrive(float time, float speed);
	virtual ~NoRotateTimedDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_AUTOMATIC_NOROTATETIMEDDRIVE_H_ */
