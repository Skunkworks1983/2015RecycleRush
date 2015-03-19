#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <Subsystems/ArmIntakerino.h>
#include <Subsystems/ArmLifter.h>
#include <Subsystems/ArmWristerino.h>
#include <Subsystems/Craaaw.h>
#include "Subsystems/ToteIntakerino.h"
#include <string>
#include "Commands/Command.h"
#include "Subsystems/DriveBae.h"
#include "OI.h"
#include "WPILib.h"
#include "Subsystems/ToteLifterino.h"
#include "Subsystems/Pneumatics.h"
#include "Subsystems/AutoCanGrabber.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */

class DriveBae;
class ArmLifter;
class ArmWristerino;
class ArmIntakerino;
class ToteIntakerino;
class ToteLifterino;
class Craaaw;
class Pneumatics;
class CommandBase: public Command {
public:
	CommandBase(char const *name);
	CommandBase();
	~CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
	static DriveBae *driveBae;
	static Craaaw *craaaw;
	static ArmLifter *armLifter;
	static ArmWristerino *armWristerino;
	static ArmIntakerino *armIntakerino;
	static ToteIntakerino *toteIntakerino;
	static ToteLifterino *toteLifterino;
	static OI *oi;
	static Pneumatics *pneumatics;
	static AutoCanGrabber *autoCanGrabber;
};

#endif

