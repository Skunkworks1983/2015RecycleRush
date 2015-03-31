/*
 * ProtoRobot.cpp
 *
 *  Created on: Jan 11, 2015
 *      Author: Administrator
 */

#include <CANTalon.h>
#include <Commands/Automatic/MoveUntilForce.h>
#include <Commands/Automatic/TimedDrive.h>
#include <Commands/Autonomous/Autonomous.h>
#include <Commands/Drivebase/ZeroGyro.h>
#include <Commands/Scheduler.h>
#include <Encoder.h>
#include <GyroDriver/IMU.h>
#include <LiveWindow/LiveWindow.h>
#include <OI.h>
#include <OmegaSupreme.h>
#include <PIDController.h>
#include <RobotBase.h>
#include <RobotMap.h>
#include <stdio.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Subsystems/DriveBase.h>
#include <Subsystems/ToteLifter.h>
#include <Timer.h>
#include <utilities/Time.h>

OmegaSupreme::OmegaSupreme() {
	lw = NULL;
	autonomousCommand = NULL;
	chooser = NULL;
	shouldRun = true;
}

OmegaSupreme::~OmegaSupreme() {
	delete autonomousCommand;
	delete chooser;
}

void OmegaSupreme::RobotInit() {
	CommandBase::init();
	lw = LiveWindow::GetInstance();

	chooser = new SendableChooser();
	chooser->AddDefault("Get Center Can", Autonomous::createGetCenterCan());
	chooser->AddObject("Pickup Can", Autonomous::createStartWithCan());
	chooser->AddObject("Blank", new Autonomous());
	chooser->AddObject("Drive Into Auto Zone",
			Autonomous::createSimpleDriveForward());

	SmartDashboard::PutData("Auto Modes", chooser);

	CommandBase::oi->registerButtonListeners();

	if (CommandBase::driveBase != NULL) {
		SmartDashboard::PutData("Zero yaw", new ZeroGyro);
		bool zeroed = false;
		double initialTime = Time::getTime();
		while (!zeroed) {
			bool isCalibrating =
					CommandBase::driveBase->getGyro()->IsCalibrating();
			if (!isCalibrating || Time::getTime() - initialTime > GYRO_TIMEOUT) {
				Wait(0.2);
				CommandBase::driveBase->getGyro()->ZeroYaw();
				//CommandBase::driveBae->startRotPID(); // enable the pid. May want to move this
				zeroed = true;
			}
		}
	}

	//Easy/quick testing of motors on drivebase in case of issues.
	SmartDashboard::PutData("Front left",
			new TimedDrive(1.0, .2, DriveBase::MotorSide::FRONT_LEFT, true));
	SmartDashboard::PutData("Front right",
			new TimedDrive(1.0, .2, DriveBase::MotorSide::FRONT_RIGHT, true));
	SmartDashboard::PutData("Back left",
			new TimedDrive(1.0, .2, DriveBase::MotorSide::BACK_LEFT, true));
	SmartDashboard::PutData("Back right",
			new TimedDrive(1.0, .2, DriveBase::MotorSide::BACK_RIGHT, true));
}

void OmegaSupreme::AutonomousInit() {
	Scheduler::GetInstance()->RemoveAll();
	SmartDashboard::PutString("auto", "insideAutoInit!");
	CommandBase::toteLifter->getEncoder()->Reset();
	autonomousCommand = (Command *) chooser->GetSelected();
	autonomousCommand->Start();
}

void OmegaSupreme::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
	if (!autonomousCommand->IsRunning() && shouldRun) {
		autonomousCommand = (Command *) chooser->GetSelected();
		autonomousCommand->Start();
		shouldRun = false;
	}
}

void OmegaSupreme::TeleopInit() {
	if (autonomousCommand != NULL) {
		autonomousCommand->Cancel();
	} else {
		CommandBase::toteLifter->getEncoder()->Reset();
	}
	CommandBase::driveBase->setModeAll(
			CANSpeedController::ControlMode::kPercentVbus);
	Scheduler::GetInstance()->RemoveAll();
}

void OmegaSupreme::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
	if (autonomousCommand != NULL) {
		if (autonomousCommand->IsRunning()) {
			autonomousCommand->Cancel();
		}
		if (chooser->GetSelected() != NULL) {
			if (((Command *) chooser->GetSelected())->IsRunning()) {
				((Command *) chooser->GetSelected())->Cancel();
			}
		}
	}
}

void OmegaSupreme::DisabledInit() {
	Scheduler::GetInstance()->RemoveAll();
}

void OmegaSupreme::TestInit() {
	Scheduler::GetInstance()->RemoveAll();
}

void OmegaSupreme::TestPeriodic() {
	Scheduler::GetInstance()->Run();
	lw->Run();
}

START_ROBOT_CLASS(OmegaSupreme);
