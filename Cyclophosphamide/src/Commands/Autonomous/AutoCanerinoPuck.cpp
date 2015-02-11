/*
 * JustDrive.cpp
 *
 *  Created on: Jan 16, 2015
 *      Author: Administrator
 */

#include <Commands/AutoCanCollecterino/Wencherino.h>
#include "Autonomous.h"
#include "../AutoCanCollecterino/Armerino.h"
#include "../Automatic/BestDrive.h"

Autonomous *Autonomous::createAutoCanerinoPuck() {
	Autonomous *cmd = new Autonomous("Autonomous-AutoCanerinoPuck");
	cmd->AddSequential(new Armerino(false));
	cmd->AddParallel(new Wencherino(AutoCanerinoPuck::WenchSetting::bringIn));
	cmd->AddParallel(createDriveDistance(AUTO_CAN_DRIVE_BACK, BestDrive::forward));
	cmd->AddParallel(new Armerino(true));
	cmd->AddSequential(new Wencherino(AutoCanerinoPuck::WenchSetting::letDown));
	cmd->AddSequential(new Wencherino(AutoCanerinoPuck::WenchSetting::bringIn));
	return cmd;
}
