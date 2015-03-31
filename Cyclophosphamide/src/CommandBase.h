#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <Subsystems/ArmIntake.h>
#include <Subsystems/ArmLifter.h>
#include <Subsystems/ArmWrist.h>
#include <Subsystems/CanStabilizer.h>
#include <Subsystems/DriveBase.h>
#include <Subsystems/ToteIntake.h>
#include <Subsystems/ToteLifter.h>
#include <string>
#include "Commands/Command.h"
#include "OI.h"
#include "WPILib.h"
#include "Subsystems/Pneumatics.h"
#include "Subsystems/AutoCanGrabber.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */

class DriveBase;
class ArmLifter;
class ArmWrist;
class ArmIntake;
class ToteIntake;
class ToteLifter;
class CanStabilizer;
class Pneumatics;
class CommandBase: public Command {
public:
	CommandBase(char const *name);
	CommandBase();
	~CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
	static DriveBase *driveBase;
	static CanStabilizer *canStabilizer;
	static ArmLifter *armLifter;
	static ArmWrist *armWrist;
	static ArmIntake *armIntake;
	static ToteIntake *toteIntake;
	static ToteLifter *toteLifter;
	static OI *oi;
	static Pneumatics *pneumatics;
	static AutoCanGrabber *autoCanGrabber;
};

#endif

