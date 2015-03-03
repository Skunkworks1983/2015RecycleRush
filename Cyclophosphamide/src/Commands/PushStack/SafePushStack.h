/*
 * SafePushStack.h
 *
 *  Created on: Feb 26, 2015
 *      Author: S-4020395
 */

#ifndef SRC_COMMANDS_PUSHSTACK_SAFEPUSHSTACK_H_
#define SRC_COMMANDS_PUSHSTACK_SAFEPUSHSTACK_H_

#include <Commands/CommandGroup.h>
#include <Subsystems/StackPusher.h>

/*
 *
 */
class SafePushStack: public CommandGroup {
public:
	SafePushStack(StackPusher::PushState state, float timeout);
	virtual ~SafePushStack();
};

#endif /* SRC_COMMANDS_PUSHSTACK_SAFEPUSHSTACK_H_ */
