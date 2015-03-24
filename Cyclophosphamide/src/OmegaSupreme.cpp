/*
 * ProtoRobot.cpp
 *
 *  Created on: Jan 11, 2015
 *      Author: Administrator
 */

#include <AnalogInput.h>
#include <Commands/Automatic/MoveUntilForce.h>
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
#include <Subsystems/ArmLifter.h>
#include <Subsystems/DriveBae.h>
#include <Subsystems/ToteLifterino.h>
#include <Timer.h>
#include <utilities/Time.h>

OmegaSupreme::OmegaSupreme() {
	PIDChange = 0;
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

	// Create autonomous
	chooser = new SendableChooser();
	chooser->AddDefault("Can Then Zone",
			Autonomous::createStartWithCanThenDrive());
	chooser->AddObject("Just Get Can", Autonomous::createStartWithCan());
	chooser->AddObject("Blank", new Autonomous());
	chooser->AddObject("Drive forward", Autonomous::createSimpleDriveForward());
	chooser->AddObject("driveTillForce",
			new MoveUntilForce(-.4, -.75, MoveUntilForce::ForceAxis::Y));
	chooser->AddObject("getCenterCan", Autonomous::createGetCenterCan());
	SmartDashboard::PutData("Auto Modes", chooser);

	out.open("autolog", std::ios::out);
	out << "~~~~~~~STAAARTING LOG~~~~~~~" << std::endl;

	CommandBase::oi->registerButtonListeners();

	if (CommandBase::driveBae != NULL) {
		SmartDashboard::PutData("Zero yaw", new ZeroGyro);
		bool zeroed = false;
		double initialTime = Time::getTime();
		while (!zeroed) {
			bool isCalibrating =
					CommandBase::driveBae->getGyro()->IsCalibrating();
			if (!isCalibrating || Time::getTime() - initialTime > GYRO_TIMEOUT) {
				Wait(0.2);
				CommandBase::driveBae->getGyro()->ZeroYaw();
				//CommandBase::driveBae->startRotPID(); // enable the pid. May want to move this
				zeroed = true;
			}
			SmartDashboard::PutString("auto", "zeroing");
		}
	}
	SmartDashboard::PutString("auto", "end of RobotInit!");
	//autonomousCommand = Autonomous::createStartWithCan();
	out << "initialized auto" << std::endl;
	SmartDashboard::PutNumber("P", TOTE_LIFTER_PID_P);
	SmartDashboard::PutNumber("I", TOTE_LIFTER_PID_I);
	SmartDashboard::PutNumber("D", TOTE_LIFTER_PID_D);
}

void OmegaSupreme::AutonomousInit() {
	Scheduler::GetInstance()->RemoveAll();
	SmartDashboard::PutString("auto", "insideAutoInit!");
	CommandBase::toteLifterino->getEncoder()->Reset();
	autonomousCommand = (Command *) chooser->GetSelected();
	autonomousCommand->Start();
	out << "Autonomous init ran" << std::endl;
	out.flush();
	running = autonomousCommand->IsRunning();
	if (running) {
		out << "~FIRST~ Running! ~FIRST~" << std::endl;
	} else {
		out << "~FIRST~ Not Running ~FIRST~" << std::endl;
	}
}

void OmegaSupreme::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
	if (!autonomousCommand->IsRunning() && shouldRun) {
		autonomousCommand = (Command *) chooser->GetSelected();
		autonomousCommand->Start();
		out << "Did the should run" << std::endl;
		out.flush();
		shouldRun = false;
	}

	if (!autonomousCommand->IsRunning() && running) {
		out << "Not Running" << std::endl;
		out.flush();
		running = false;
	} else if (autonomousCommand->IsRunning() && !running) {
		out << "Running!" << std::endl;
		out.flush();
		running = true;
	}
	WatchDogg();
}

void OmegaSupreme::TeleopInit() {
	if (autonomousCommand != NULL) {
		autonomousCommand->Cancel();
	} else {
		CommandBase::toteLifterino->getEncoder()->Reset();
	}
	Scheduler::GetInstance()->RemoveAll();
	CommandBase::driveBae->getGyro()->ZeroYaw();
	CommandBase::driveBae->zeroPIDOutput();

}

void OmegaSupreme::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();

	SmartDashboard::PutNumber("ElevatorError",
			CommandBase::toteLifterino->getPID()->GetError());

	WatchDogg();
}

void OmegaSupreme::DisabledInit() {
	Scheduler::GetInstance()->RemoveAll();
}

void OmegaSupreme::TestInit() {
	Scheduler::GetInstance()->RemoveAll();
	//SmartDashboard::PutData(CommandBase::pneumatics);
	//SmartDashboard::PutData("Run compressor", new UpdateCompressor());
//	Command *cmd = new FollowVision(true);
//	cmd->Start();
}

void OmegaSupreme::TestPeriodic() {
	Scheduler::GetInstance()->Run();
	SmartDashboard::PutNumber("armPos",
			CommandBase::armLifter->getLiftPot()->PIDGet());
	lw->Run();
}

void OmegaSupreme::WatchDogg() {
// there are now doggs to watch
// lmao XDDD
}

START_ROBOT_CLASS(OmegaSupreme);
