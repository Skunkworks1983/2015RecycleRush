/*
 * JustDrive.cpp
 *
 *  Created on: Jan 16, 2015
 *      Author: Administrator
 */

#include <Commands/AutoCanCollecterino/Wencherino.h>
#include "Autonomous.h"
#include "../AutoCanCollecterino/Armerino.h"

Autonomous *Autonomous::createAutoCanerinoPuck() {
	Autonomous *cmd = new Autonomous("Autonomous-AutoCanerinoPuck");
	cmd->AddSequential(new Armerino(false));
	cmd->AddParallel(new Wincherino(AutoCanerinoPuck::WinchSetting::bringIn));
	cmd->AddParallel(createJustDrive(AUTO_CAN_DRIVE_BACK, 0));
	cmd->AddParallel(new Armerino(true));
	cmd->AddSequential(new Wincherino(AutoCanerinoPuck::WinchSetting::letDown));
	cmd->AddSequential(new Wincherino(AutoCanerinoPuck::WinchSetting::bringIn));
	return cmd;
}
