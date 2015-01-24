<<<<<<< HEAD
#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <string>
#include "Commands/Command.h"
#include "Subsystems/DriveBase.h"
#include "Subsystems/ToteIntakerino.h"
#include "Subsystems/ToteLifterino.h"
#include "OI.h"
#include "WPILib.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command
{
public:
	CommandBase(char const *name);
	CommandBase();
	~CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
	static DriveBase *driveBase;
	static ToteIntakerino *tote_intakerino;
	static ToteLifterino *tote_lifterino;
	static OI *oi;
};

#endif
=======
#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <Subsystems/CollecterinoArms.h>
#include "Subsystems/ToteIntakerino.h"
#include <string>
#include "Commands/Command.h"
#include "Subsystems/DriveBase.h"
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
class CommandBase: public Command
{
public:
	CommandBase(char const *name);
	CommandBase();
	~CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
	static DriveBase *driveBase;
	static CanCollecterino *canCollecterino;
	static ToteIntakerino *tote_intakerino;
	static OI *oi;
};

#endif
>>>>>>> 023b1b703ef98984b1a130030eb74c1871294efe
