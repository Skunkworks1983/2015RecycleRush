#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <string>
#include "Commands/Command.h"
#include "Subsystems/DriveBase.h"
#include "Subsystems/CanCollecterino.h"
#include "Subsystems/ToteIntakerino.h"
#include "Subsystems/ToteLifterino.h"
#include "Subsystems/Craaaw.h"
#include "OI.h"
#include "WPILib.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class DriveBase;
class CanCollecterino;
class ToteIntakerino;
class ToteLifterino;
class Craaaw;
class CommandBase: public Command// Can Collector
{
public:
	CommandBase(char const *name);
	CommandBase();
	~CommandBase();
	static void init();

	// Create a single static instance of all of your subsystems
	static DriveBase *driveBase;
	static Craaaw *craaaw;
	static CanCollecterino *canCollecterino;
	static ToteIntakerino *toteIntakerino;
	static ToteLifterino *toteLifterino;
	static OI *oi;
};

#endif
