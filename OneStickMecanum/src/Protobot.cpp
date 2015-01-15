/*
 * ProtoRobot.cpp
 *
 *  Created on: Jan 11, 2015
 *      Author: Administrator
 */

#include "Protobot.h"
#include "WPILib.h"
#include "Commands/Command.h"

#include "CommandBase.h"
#include "RobotMap.h"

#include "Commands/MecanumDrive.h"

Protobot::Protobot() {
	lw = NULL;
	autonomousCommand = NULL;
}

Protobot::~Protobot() {
	delete autonomousCommand;
}

void Protobot::RobotInit() {
	CommandBase::init();
	autonomousCommand = new MecanumDrive();
	lw = LiveWindow::GetInstance();
}

void Protobot::AutonomousInit() {
	if (autonomousCommand != NULL) {
		autonomousCommand->Start();
	}
}

void Protobot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Protobot::TeleopInit() {
	if (autonomousCommand != NULL) {
		autonomousCommand->Cancel();
	}
	Scheduler::GetInstance()->RemoveAll();
}

void Protobot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Protobot::DisabledInit() {
	Scheduler::GetInstance()->RemoveAll();
}

void Protobot::TestInit() {
	Scheduler::GetInstance()->RemoveAll();
}

void Protobot::TestPeriodic() {
	lw->Run();
}



START_ROBOT_CLASS(Protobot);
