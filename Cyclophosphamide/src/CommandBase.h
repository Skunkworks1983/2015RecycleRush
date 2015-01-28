#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <Subsystems/CollecterinoArms.h>
#include <Subsystems/AutoCanerino/AutoCanerinoPuck.h>
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

class DriveBae;
class CanCollecterino;
class ToteIntakerino;
class AutoCanerinoPuck;
class CommandBase: public Command
{
public:
	CommandBase(char const *name);
	CommandBase();
	~CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
	static DriveBae *driveBase;
	static AutoCanerinoPuck *autoCanerinoPuck;
	static CanCollecterino *canCollecterino;
	static ToteIntakerino *tote_intakerino;
	static OI *oi;
};

#endif
