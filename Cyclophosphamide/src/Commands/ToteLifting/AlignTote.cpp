/*
 * AllignTote.cpp
 *
 *  Created on: Mar 3, 2015
 *      Author: S-4020395
 */

#include <Commands/ToteIntake/ToteIntake.h>
#include <Commands/ToteLifting/AlignTote.h>

AlignTote::AlignTote() {
	AddSequential(new ToteIntake(ToteIntake::Direction::forward), .5);
	AddSequential(new ToteIntake(ToteIntake::Direction::reverse), 1);
}

AlignTote::~AlignTote() {
}

