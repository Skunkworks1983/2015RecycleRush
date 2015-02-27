/*
 * SafePushStack.cpp
 *
 *  Created on: Feb 26, 2015
 *      Author: S-4020395
 */

#include <Commands/PushStack/SafePushStack.h>
#include <Commands/CanCollecterino/Craaaw/CraaawActuate.h>
#include "PushStack.h"

SafePushStack::SafePushStack(StackPusher::PushState state, float timeout) {
	AddSequential(new CraaawActuate(DoubleSolenoid::Value::kReverse));
	AddSequential(new PushStack(state, timeout));
}

SafePushStack::~SafePushStack() {
}

