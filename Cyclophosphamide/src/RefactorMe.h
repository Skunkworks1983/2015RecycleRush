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

class RefactorMeBot : public IterativeRobot {
private:
	Command *autonomousCommand;
	LiveWindow *lw;
	SendableChooser *chooser;

public:
	RefactorMeBot();
	~RefactorMeBot();
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
