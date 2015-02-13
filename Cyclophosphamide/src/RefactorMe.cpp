/*
 * ProtoRobot.cpp
 *
 *  Created on: Jan 11, 2015
 *      Author: Administrator
 */

#include <Commands/Automatic/TimedDrive.h>
#include <Commands/Drivebase/ZeroGyro.h>
#include <RefactorMe.h>
#include "WPILib.h"
#include "Commands/Command.h"

#include "CommandBase.h"
#include "RobotMap.h"

#include "Commands/Autonomous/Autonomous.h"


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
	chooser->AddObject("Drive forward 1000 ticks", Autonomous::createDriveDistance(360.0f, BestDrive::forward));
	chooser->AddObject("Drive forward 1 second", Autonomous::createDriveDuration(1.0f, -90.0f));
	chooser->AddObject("Turn 90 degrees", Autonomous::createTurnTo(90.0));
	SmartDashboard::PutData("Auto Modes", chooser);

	CommandBase::oi->registerButtonListeners();

	SmartDashboard::PutData("Zero yaw", new ZeroGyro);
	bool zeroed = false;
	double initialTime = GetFPGATime();
	while(!zeroed) {
		bool isCalibrating = false; //CommandBase::driveBae->getGyro()->IsCalibrating();
		if(!isCalibrating || GetFPGATime()-initialTime > GYRO_TIMEOUT) {
			Wait( 0.2 );
			CommandBase::driveBae->getGyro()->ZeroYaw();
			CommandBase::driveBae->startRotPID(); // enable the pid. May want to move this
			zeroed = true;
		}
	}
}

void RefactorMeBot::AutonomousInit() {
	Scheduler::GetInstance()->RemoveAll();
	autonomousCommand = (Command *) chooser->GetSelected();
	autonomousCommand->Start();

	float startingOffset = SmartDashboard::GetNumber("Auto angle offset", 0.0);
	CommandBase::driveBae->getGyro()->SetYawPitchRoll(startingOffset, 0.0f, 0.0f, 0.0f);
}

void RefactorMeBot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
	WatchDogg();
}

void RefactorMeBot::TeleopInit() {
	if (autonomousCommand != NULL) {
		autonomousCommand->Cancel();
	}
	Scheduler::GetInstance()->RemoveAll();
}

void RefactorMeBot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
	WatchDogg();
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

void RefactorMeBot::WatchDogg() {
	// there are no dogs to watch
	// ayy lmao
}

START_ROBOT_CLASS(RefactorMeBot);
