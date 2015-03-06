/*
 * ProtoRobot.cpp
 *
 *  Created on: Jan 11, 2015
 *      Author: Administrator
 */

#include <Commands/Automatic/TimedDrive.h>
#include <Commands/Drivebase/ZeroGyro.h>
#include <Commands/CanCollecterino/MoveArmsFancy.h>
#include <Commands/ToteIntake/ToteIntake.h>
#include <Commands/Automatic/SimpleDriveForward.h>
#include <Commands/Automatic/TurnTo.h>
#include <Commands/ToteLifting/DownUp.h>
#include <Commands/ToteLifting/zeroing/ResetElevatorEncoder.h>
#include "OmegaSupreme.h"
#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/UpdateCompressor.h"

#include "Commands/Autonomous/Scripting.h"

#include "CommandBase.h"
#include "RobotMap.h"
#include <stdio.h>

#include <Vision/VisionRunner.h>
#include "Commands/Autonomous/Autonomous.h"

OmegaSupreme::OmegaSupreme() {
	PIDChange = 0;
	lw = NULL;
	chooser = NULL;
	autonomousCommand = NULL;
	VisionRunner *vision = new VisionRunner(320, 480);
	vision->ThreadStart();
}

OmegaSupreme::~OmegaSupreme() {
	delete autonomousCommand;
	delete chooser;
}

void OmegaSupreme::RobotInit() {
	CommandBase::init();
	lw = LiveWindow::GetInstance();

	input1 = new DigitalInput(1);
	input2 = new DigitalInput(2);

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

	//chooser = Scripting::generateAutonomousModes(AUTO_SCRIPT_LOCATIONS);

	CommandBase::oi->registerButtonListeners();

	if (CommandBase::driveBae != NULL && FIELD_ORIENTED) {
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
}

void OmegaSupreme::AutonomousInit() {
	Scheduler::GetInstance()->RemoveAll();
	//((ScriptRunner*) chooser->GetSelected())->startCommand();

	autonomousCommand = (Command *) chooser->GetSelected();
	//autonomousCommand = new SimpleDriveForward(24);
	SmartDashboard::PutString("auto", "insideAutoInit!");
	CommandBase::toteLifterino->getEncoder()->Reset();
	//autonomousCommand = Autonomous::createStartWithCan();
	autonomousCommand->Start();
}

void OmegaSupreme::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
	if (!autonomousCommand->IsRunning()) {
		autonomousCommand->Start();
	}
	WatchDogg();
}

void OmegaSupreme::TeleopInit() {
	if (autonomousCommand != NULL) {
		autonomousCommand->Cancel();
	}
	Scheduler::GetInstance()->RemoveAll();
	CommandBase::driveBae->getGyro()->ZeroYaw();
	CommandBase::driveBae->zeroPIDOutput();
	CommandBase::toteLifterino->getEncoder()->Reset();
	SmartDashboard::PutData(CommandBase::craaaw);
	SmartDashboard::PutData("Can up", new MoveArmsFancy(true));
	SmartDashboard::PutData("Can down", new MoveArmsFancy(false));
	SmartDashboard::PutData("Tote intake", new ToteIntake(ToteIntake::forward));
	SmartDashboard::PutData("Get next tote", new DownUp(DownUp::load));
	SmartDashboard::PutData("Get last tote", new DownUp(DownUp::carry));
	SmartDashboard::PutData("Reset Elevator Encoder",
			new ResetElevatorEncoder());
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
			CommandBase::toteLifterino->getEncoder()->Get());

	SmartDashboard::PutNumber("driveEncoder",
			CommandBase::driveBae->getMotor(DriveBae::MotorSide::FRONT_LEFT)->GetEncPosition());

	SmartDashboard::PutNumber("lifter pos",
			CommandBase::toteLifterino->getPosition());

	SmartDashboard::PutNumber("Gyro Angle",
			CommandBase::driveBae->getGyro()->GetYaw());
	WatchDogg();
}

void OmegaSupreme::DisabledInit() {
	Scheduler::GetInstance()->RemoveAll();
}

void OmegaSupreme::TestInit() {
	Scheduler::GetInstance()->RemoveAll();
	SmartDashboard::PutData(CommandBase::pneumatics);
	SmartDashboard::PutData("Run compressor", new UpdateCompressor());
}

void OmegaSupreme::TestPeriodic() {
	lw->Run();

}

void OmegaSupreme::WatchDogg() {
// there are now doggs to watch
// lmao XDDD
	/*if (CommandBase::stackPusher->getValue()
	 == DoubleSolenoid::kForward&& CommandBase::canCollecterino->getArmPID()->GetSetpoint() == CAN_POT_UP_POSITION) {
	 CommandBase::canCollecterino->disableArms();
	 }
	 if (CommandBase::toteIntakerino->isLoaded()
	 && (CommandBase::toteLifterino->getPID()->GetSetpoint()
	 < TOTE_LIFTER_STACK_HEIGHT
	 && CommandBase::toteLifterino->getEncoder()->Get()
	 >= TOTE_LIFTER_STACK_HEIGHT - 100)) {
	 CommandBase::toteLifterino->enablePID(false);
	 } else if (CommandBase::toteIntakerino->isLoaded()
	 && (CommandBase::toteLifterino->getPID()->GetSetpoint()
	 < TOTE_LIFTER_STACK_HEIGHT)) {
	 CommandBase::toteLifterino->setSetPoints(TOTE_LIFTER_STACK_HEIGHT);
	 }*/
}

START_ROBOT_CLASS(OmegaSupreme);
