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
#include "Commands/PushStack/PushPull.h"


RefactorMeBot::RefactorMeBot() {
	lw = NULL;
	autonomousCommand = NULL;
	chooser = NULL;
}

RefactorMeBot::~RefactorMeBot() {
	delete autonomousCommand;
	delete chooser;
}

void RefactorMeBot::RobotInit() {
	CommandBase::init();
	lw = LiveWindow::GetInstance();

	// Create autonomous
	chooser = new SendableChooser();
	chooser->AddDefault("Blank", new Autonomous());
	chooser->AddObject("Drive forward 1 second", Autonomous::createJustDrive(1.0f, 0.0f));
	chooser->AddObject("Drive left 1 second", Autonomous::createJustDrive(1.0f, -90.0f));
	SmartDashboard::PutData("Auto Modes", chooser);

	SmartDashboard::PutData("Zero yaw", new ResetGyro);

	CommandBase::oi->registerButtonListeners();
}

void RefactorMeBot::AutonomousInit() {
	Scheduler::GetInstance()->RemoveAll();
	autonomousCommand = (Command *) chooser->GetSelected();
	autonomousCommand->Start();
}

void RefactorMeBot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void RefactorMeBot::TeleopInit() {
	if (autonomousCommand != NULL) {
		autonomousCommand->Cancel();
	}
	Scheduler::GetInstance()->RemoveAll();
}

void RefactorMeBot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}

void RefactorMeBot::DisabledInit() {
	Scheduler::GetInstance()->RemoveAll();
}

void RefactorMeBot::TestInit() {
	Scheduler::GetInstance()->RemoveAll();
}

void RefactorMeBot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(RefactorMeBot);
