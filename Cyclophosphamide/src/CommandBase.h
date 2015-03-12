#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <Subsystems/CanCollecterino.h>
#include <Subsystems/CanWristerino.h>
#include <Subsystems/Craaaw.h>
#include "Subsystems/OldToteIntakerino.h"
#include "Subsystems/NewToteIntakerino.h"
#include "Subsystems/CanIntakerino.h"
#include <string>
#include "Commands/Command.h"
#include "Subsystems/DriveBae.h"
#include "OI.h"
#include "WPILib.h"
#include "Subsystems/ToteLifterino.h"
#include "Subsystems/Pneumatics.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */

class DriveBae;
class CanCollecterino;
class CanWristerino;
class CanIntakerino;
class OldToteIntakerino;
class NewToteIntakerino;
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
	static CanCollecterino *canCollecterino;
	static CanWristerino *canWristerino;
	static CanIntakerino *canIntakerino;
	static NewToteIntakerino *newToteIntakerino;
	static OldToteIntakerino *oldToteIntakerino;
	static ToteLifterino *toteLifterino;
	static OI *oi;
	static Pneumatics *pneumatics;
};

#endif

