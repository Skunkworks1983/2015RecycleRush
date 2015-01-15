/*
 * ProtoRobot.h
 *
 *  Created on: Jan 11, 2015
 *      Author: Administrator
 */

#ifndef PROTOBOT_H_
#define PROTOBOT_H_

#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"

class Protobot : public IterativeRobot {
private:
	Command *autonomousCommand;
	LiveWindow *lw;
public:
	Protobot();
	~Protobot();
	virtual void RobotInit();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestInit();
	virtual void TestPeriodic();
	virtual void DisabledInit();
};

#endif /* PROTOBOT_H_ */
