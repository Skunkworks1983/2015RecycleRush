/*
 * ProtoRobot.h
 *
 *  Created on: Jan 11, 2015
 *      Author: Administrator
 */

#ifndef OMEGA_SUPREME_H_
#define OMEGA_SUPREME_H_

#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"

class OmegaSupreme: public IterativeRobot {
private:
	Command *autonomousCommand;
	LiveWindow *lw;
	SendableChooser *chooser;
	int PIDChange;
	DigitalInput *input1, *input2;
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
