/*
 * AllignTote.cpp
 *
 *  Created on: Mar 3, 2015
 *      Author: S-4020395
 */

#include <Commands/ToteIntake/NewToteIntake.h>
#include <Commands/ToteLifting/AlignTote.h>

AlignTote::AlignTote() {
	AddSequential(new NewToteIntake(NewToteIntake::Direction::forward), .5);
	AddSequential(new NewToteIntake(NewToteIntake::Direction::reverse), 1);
}

AlignTote::~AlignTote() {
}

