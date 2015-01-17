/*
 * ProtoRobot.cpp
 *
 *  Created on: Jan 11, 2015
 *      Author: Administrator
 */

#include <Commands/Automatic/AutoDrive.h>
#include "Protobot.h"
#include "WPILib.h"
#include "Commands/Command.h"

#include "CommandBase.h"
#include "RobotMap.h"

#include "Commands/Autonomous/Autonomous.h"
#include "Commands/ResetGyro.h"


Protobot::Protobot() {
	lw = NULL;
	autonomousCommand = NULL;
	chooser = NULL;
}

Protobot::~Protobot() {
	delete autonomousCommand;
	delete chooser;
}

void Protobot::RobotInit() {
	CommandBase::init();
	lw = LiveWindow::GetInstance();

	// Create autonomous
	chooser = new SendableChooser();
	chooser->AddDefault("Blank", new Autonomous());
	chooser->AddObject("Drive forward 1 second", Autonomous::createJustDrive(1.0f, 0.0f));
	chooser->AddObject("Drive left 1 second", Autonomous::createJustDrive(1.0f, -90.0f));
	SmartDashboard::PutData("Auto Modes", chooser);

	SmartDashboard::PutData("Zero yaw", new ResetGyro);
}

void Protobot::AutonomousInit() {
	Scheduler::GetInstance()->RemoveAll();
	autonomousCommand = (Command *) chooser->GetSelected();
	autonomousCommand->Start();
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
