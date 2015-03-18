/*
 * ProtoRobot.cpp
 *
 *  Created on: Jan 11, 2015
 *      Author: Administrator
 */

#include <AnalogInput.h>
#include <CANTalon.h>
#include <Commands/Autonomous/Autonomous.h>
#include <Commands/Drivebase/ZeroGyro.h>
#include <Commands/Scheduler.h>
#include <DigitalInput.h>
#include <Encoder.h>
#include <GyroDriver/IMU.h>
#include <Joystick.h>
#include <LiveWindow/LiveWindow.h>
#include <OI.h>
#include <OmegaSupreme.h>
#include <RobotBase.h>
#include <stdio.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Subsystems/CanCollecterino.h>
#include <Subsystems/DriveBae.h>
#include <Subsystems/ToteLifterino.h>
#include <Timer.h>
#include <Utility.h>

OmegaSupreme::OmegaSupreme() {
	PIDChange = 0;
	lw = NULL;
	autonomousCommand = NULL;
	shouldRun = true;
}

OmegaSupreme::~OmegaSupreme() {
	delete autonomousCommand;
}

void OmegaSupreme::RobotInit() {
	CommandBase::init();
	lw = LiveWindow::GetInstance();

	input1 = new DigitalInput(1);
	input2 = new DigitalInput(2);

<<<<<<< HEAD
	// Create autonomous

	chooser = new SendableChooser();
	chooser->AddDefault("Start with can", Autonomous::createStartWithCan());
	chooser->AddObject("Blank", new Autonomous());
	chooser->AddObject("Drive forward", Autonomous::createSimpleDriveForward());
	/*chooser->AddObject("Drive forward 24 inches",
	 Autonomous::createDriveDistance(24, BestDrive::forward));
	 chooser->AddObject("Drive forward 1 second",
	 Autonomous::createDriveDuration(1.0f, -90.0f));
	 chooser->AddObject("Turn 90 degrees", Autonomous::createTurnTo(90.0));*/
	SmartDashboard::PutData("Auto Modes", chooser);

	chooser = Scripting::generateAutonomousModes(AUTO_SCRIPT_LOCATIONS);
	SmartDashboard::PutData("Auto Modes", chooser);
=======
	out.open("autolog", std::ios::out);
	out << "~~~~~~~STAAARTING LOG~~~~~~~" << std::endl;
>>>>>>> master

	CommandBase::oi->registerButtonListeners();

	if (CommandBase::driveBae != NULL) {
		SmartDashboard::PutData("Zero yaw", new ZeroGyro);
		bool zeroed = false;
		double initialTime = GetFPGATime();
		while (!zeroed) {
			bool isCalibrating =
					CommandBase::driveBae->getGyro()->IsCalibrating();
			if (!isCalibrating /*|| GetFPGATime() - initialTime > GYRO_TIMEOUT*/) {
				Wait(0.2);
				CommandBase::driveBae->getGyro()->ZeroYaw();
				//CommandBase::driveBae->startRotPID(); // enable the pid. May want to move this
				zeroed = true;
			}
			SmartDashboard::PutString("auto", "zeroing");
		}
	}
	SmartDashboard::PutString("auto", "end of RobotInit!");
	autonomousCommand = Autonomous::createStartWithCan();
	out << "initialized auto" << std::endl;
}

void OmegaSupreme::AutonomousInit() {
	Scheduler::GetInstance()->RemoveAll();
	SmartDashboard::PutString("auto", "insideAutoInit!");
	CommandBase::toteLifterino->getEncoder()->Reset();
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

	SmartDashboard::PutNumber("motorLEFTCurrentOMG",
			CommandBase::toteLifterino->getLeftMotor()->GetOutputCurrent());
	SmartDashboard::PutNumber("motorRIGHTCurrentOMG",
			CommandBase::toteLifterino->getRightMotor()->GetOutputCurrent());

	SmartDashboard::PutNumber("armPot",
			CommandBase::canCollecterino->getLiftPot()->PIDGet());

	SmartDashboard::PutBoolean("Digital input1", input1->Get());
	SmartDashboard::PutBoolean("Digital input2", input2->Get());

	SmartDashboard::PutNumber("Can arm pot",
			CommandBase::canCollecterino->getLiftPot()->GetValue());

	SmartDashboard::PutNumber("elevatorEnc",
			CommandBase::toteLifterino->getEncoder()->PIDGet());
	SmartDashboard::PutNumber("driveEncoder",
			CommandBase::driveBae->getMotor(DriveBae::MotorSide::FRONT_LEFT)->GetEncPosition());

	SmartDashboard::PutNumber("lifter pos",
			CommandBase::toteLifterino->getPosition());

	SmartDashboard::PutNumber("Gyro Angle",
			CommandBase::driveBae->getGyro()->GetYaw());

	SmartDashboard::PutNumber("xAxisJoystick",
			CommandBase::oi->getJoystickOperator()->GetAxis(
					Joystick::AxisType::kXAxis));
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
	lw->Run();
}

void OmegaSupreme::WatchDogg() {
// there are now doggs to watch
// lmao XDDD
}

START_ROBOT_CLASS(OmegaSupreme);
