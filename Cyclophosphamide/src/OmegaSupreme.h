/*
 * ProtoRobot.h
 *
 *  Created on: Jan 11, 2015
 *      Author: Administrator
 */

#ifndef OMEGA_SUPREME_H_
#define OMEGA_SUPREME_H_

#include <IterativeRobot.h>
#include <iostream>
#include <fstream>

class Command;
class DigitalInput;
class LiveWindow;

class OmegaSupreme: public IterativeRobot {
private:
	Command *autonomousCommand;
	LiveWindow *lw;
	int PIDChange;
	DigitalInput *input1, *input2;
	std::ofstream out;
	bool running;
	bool shouldRun;

public:
	OmegaSupreme();
	~OmegaSupreme();
	virtual void RobotInit();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestInit();
	virtual void TestPeriodic();
	virtual void DisabledInit();
	void WatchDogg();
};

#endif /* PROTOBOT_H_ */
