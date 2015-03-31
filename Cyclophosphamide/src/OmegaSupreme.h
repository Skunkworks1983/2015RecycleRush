/*
 * ProtoRobot.h
 *
 *  Created on: Jan 11, 2015
 *      Author: Administrator
 */

#ifndef OMEGA_SUPREME_H_
#define OMEGA_SUPREME_H_

#include <IterativeRobot.h>

class SendableChooser;

class Command;
class DigitalInput;
class LiveWindow;

class OmegaSupreme: public IterativeRobot {
private:
	Command *autonomousCommand;
	LiveWindow *lw;
	SendableChooser *chooser;
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
	void WatchDog();
};

#endif /* PROTOBOT_H_ */
