/*
 * MoveUntilTotes.h
 *
 *  Created on: Mar 22, 2015
 *      Author: s-4020395
 */

#ifndef SRC_COMMANDS_AUTOMATIC_MOVEUNTILTOTES_H_
#define SRC_COMMANDS_AUTOMATIC_MOVEUNTILTOTES_H_

#include <CommandBase.h>

/*
 *
 */
class MoveUntilForce : public CommandBase {
public:
	enum ForceAxis {
		X, Y, Z
	};
private:
	double speed, gForce, measuredMax;
	ForceAxis axis;
public:
	MoveUntilForce(double speed, double gForce, ForceAxis axis);
	virtual ~MoveUntilForce();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_AUTOMATIC_MOVEUNTILTOTES_H_ */
