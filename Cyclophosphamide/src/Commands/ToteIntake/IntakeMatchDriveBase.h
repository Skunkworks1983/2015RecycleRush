/*
 * IntakeMatchDriveBase.h
 *
 *  Created on: Mar 3, 2015
 *      Author: S-4020395
 */

#ifndef SRC_COMMANDS_TOTEINTAKE_INTAKEMATCHDRIVEBASE_H_
#define SRC_COMMANDS_TOTEINTAKE_INTAKEMATCHDRIVEBASE_H_
#include "WPILib.h"
#include <CommandBase.h>
/*
 *
 */
class IntakeMatchDriveBase: public CommandBase {
public:
	IntakeMatchDriveBase();
	virtual ~IntakeMatchDriveBase();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_TOTEINTAKE_INTAKEMATCHDRIVEBASE_H_ */
