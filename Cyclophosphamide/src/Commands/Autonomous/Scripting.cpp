/*
 * Scripting.cpp
 *
 *  Created on: Feb 13, 2015
 *      Author: s-4020395
 */

#include <Commands/Autonomous/Scripting.h>
#include "WPILib.h"
#include "Autonomous.h"
#include "../../Robotmap.h"
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

ScriptCommand::ScriptCommand(Command *start) {
	this->local = start;
	SmartDashboard::PutNumber("TurnTo Angle", 0);
}
void ScriptCommand::startCommand() {
	Scheduler::GetInstance()->AddCommand(local);
}
ScriptCommand::~ScriptCommand() {
	delete local;
}
ScriptLoader::ScriptLoader(char *fName) {
	this->fileName = fName;
}
ScriptLoader::~ScriptLoader() {
	delete fileName;
}
void ScriptLoader::startCommand() {
	int size = 0;
	char *rawData = Scripting::readFromFile(fileName, size);
	Scheduler::GetInstance()->AddCommand(
			Scripting::createCommand(size, rawData));
	delete rawData;
}
char* Scripting::readFromFile(char *fileName, int &size) {
	FILE* f = fopen(fileName, "r");
	fseek(f, 0, SEEK_END);
	size = ftell(f);
	char* rawData = new char[size + 1];
	rewind(f);
	fread(rawData, sizeof(char), size, f);
	fclose(f);
	rawData[size] = '\0';
	delete f;
	return rawData;
}
Autonomous *Scripting::createCommand(int size, char *rawData) {
	int argc = 0;
	char ** argv = new char*[AUTO_SCRIPT_MAXLINES];
	int lineStart = 0, i = 0;
	for (i = 0; i < size; i++) {
		if (rawData[i] == '\n') {
			argv[argc] = new char[i - lineStart + 1];
			memcpy(argv[argc], &(rawData[lineStart]),
					sizeof(char) * (i - lineStart));
			argv[argc][i - lineStart] = '\0';
			argc++;
			lineStart = i + 1;
		}
	}
	Autonomous *cmd = new Autonomous(argc, argv);
	for (i = 0; i < argc; i++) {
		delete argv[i];
	}
	delete argv;
	return cmd;
}
SendableChooser *Scripting::generateAutonomousModes(char *scriptLocations) {
	SendableChooser * chooser = new SendableChooser();
//	chooser->AddDefault("Triple Tote",
//			new ScriptCommand(Autonomous::createTripleTote()));
	chooser->AddObject("Turn To",
			new ScriptCommand(
					Autonomous::createTurnTo(
							SmartDashboard::GetNumber("TurnTo Angle"))));
	chooser->AddObject("Turning Triple Tote",
			new ScriptCommand(Autonomous::createTurningTripleTote()));
	chooser->AddObject("Drive Distance",
			new ScriptCommand(
					Autonomous::createDriveDistance(AUTONOMOUS_DEFAULT_DISTANCE,
							BestDrive::Direction::forward)));
	chooser->AddObject("Drive Duration",
			new ScriptCommand(
					Autonomous::createDriveDuration(AUTONOMOUS_DEFAULT_TIME,
							BestDrive::Direction::forward)));
	chooser->AddObject("Blank", new Autonomous());
	chooser->AddDefault("Blank", new Autonomous());
	chooser->AddObject("Drive forward 360 ticks",
			Autonomous::createDriveDistance(360.0f, BestDrive::forward));
	chooser->AddObject("Drive forward 1 second",
			Autonomous::createDriveDuration(1.0f, -90.0f));
	chooser->AddObject("Turn 90 degrees", Autonomous::createTurnTo(90.0));
	DIR * dp;
	struct dirent * ep;
	dp = opendir(scriptLocations);
	if (dp != NULL) {
		while (ep = readdir(dp)) {
			char * fileName = new char[50];
			sprintf(fileName, "%s%s", scriptLocations, ep->d_name);
			printf("Adding Autonomous Mode: %s\n", fileName);
			chooser->AddObject(ep->d_name, new ScriptLoader(fileName));
		}
		closedir(dp);
	} else {
		printf("Unable to read directory %s\n", scriptLocations);
	}
	delete dp;
	delete ep;
	return chooser;
}
