#include "Autonomous.h"
#include "../Automatic/BestDrive.h"
#include "../Automatic/TurnTo.h"
#include "../CanCollecterino/Arms/Induct.h"
#include "../CanCollecterino/Arms/MoveArms.h"
#include "../CanCollecterino/Arms/MoveWrist.h"
#include "../CanCollecterino/Craaaw/CraaawActuate.h"
#include "../CanCollecterino/Craaaw/CraaawUnactuate.h"
#include "../CanCollecterino/Collect.h"
#include "../CanCollecterino/PutUp.h"
#include "../CanCollecterino/SetDown.h"
#include "../PushStack/PushPull.h"
#include "../PushStack/PushStack.h"
#include "../ToteHandling/LiftToHeight.h"
#include "../ToteHandling/ToteIntake.h"

Autonomous::Autonomous() :
		CommandGroup("Autonomous-Blank") {
}
Autonomous::Autonomous(char *style) :
		CommandGroup(style) {
}
Autonomous::Autonomous(int argc, char **argv) :
		CommandGroup("Autonomous") {
	int i = 0;
	char typeA = '0', typeB = '0', cmdType = '0';
	float arg = 0.0;
	for (i = 0; i < argc; i++) {
		if (argv[i][0] == '#') {
			continue;
		}
		sscanf(argv[i], "%c\t%c%c\t%f", &cmdType, &typeA, &typeB, &arg);
		Command *use = NULL;
		switch (AUTO_SCRIPT_CHARMASK(typeA, typeB)) {
		case AUTO_SCRIPT_CHARMASK('d', 'f'):
			use = new BestDrive(arg, BestDrive::Direction::forward);
			break;
		case AUTO_SCRIPT_CHARMASK('d', 'b'):
			use = new BestDrive(arg, BestDrive::Direction::backward);
			break;
		case AUTO_SCRIPT_CHARMASK('d', 'r'):
			use = new BestDrive(arg, BestDrive::Direction::right);
			break;
		case AUTO_SCRIPT_CHARMASK('d', 'l'):
			use = new BestDrive(arg, BestDrive::Direction::left);
			break;
		case AUTO_SCRIPT_CHARMASK('t', 't'):
			use = new TurnTo(arg);
			break;
		case AUTO_SCRIPT_CHARMASK('w','f'):
			use = new WaitCommand(arg);
			break;
		case AUTO_SCRIPT_CHARMASK('w','u'):
			use = new WaitUntilCommand(arg);
			break;
		case AUTO_SCRIPT_CHARMASK('c','c'):
			use = new Collect();
			break;
		case AUTO_SCRIPT_CHARMASK('t','i'):// tote intake forward
			use = new ToteIntake(ToteIntake::Direction::forward);
			break;
		case AUTO_SCRIPT_CHARMASK('t','o'):// tote reverse forward
					use = new ToteIntake(ToteIntake::Direction::reverse);
					break;
		case AUTO_SCRIPT_CHARMASK('t','s'):// tote intake stop
					use = new ToteIntake(ToteIntake::Direction::stopped);
					break;
		case AUTO_SCRIPT_CHARMASK('t','l'):
			use = new LiftToHeight((double)arg);
			break;
		case AUTO_SCRIPT_CHARMASK('p','i'):
			use = new PushStack(StackPusher::PushState::pull, arg);
			break;
		case AUTO_SCRIPT_CHARMASK('p','o'):
			use = new PushStack(StackPusher::PushState::push, arg);
			break;
		case AUTO_SCRIPT_CHARMASK('p','p'):
			use = new PushPull();
			break;
		case AUTO_SCRIPT_CHARMASK('p','u')://Put up can
			use = new PutUp();
			break;
		case AUTO_SCRIPT_CHARMASK('s','d')://Set down can
			use = new SetDown();
			break;
		case AUTO_SCRIPT_CHARMASK('c','o'):// crawwwww Actuate out
			use = new CraaawActuate(true);
			break;
		case AUTO_SCRIPT_CHARMASK('c','i'):// crawwww Actuate in
			use = new CraaawActuate(false);
			break;
		case AUTO_SCRIPT_CHARMASK('c','u'):// crawh Unactuate
			use = new CraaawUnactuate();
			break;
		case AUTO_SCRIPT_CHARMASK('a','i'): //Arms Induct
			use = new Induct();
			break;
		case AUTO_SCRIPT_CHARMASK('a','u')://Arms up
			use = new MoveArms(true);
			break;
		case AUTO_SCRIPT_CHARMASK('a','d')://Arms down
			use = new MoveArms(false);
			break;
		case AUTO_SCRIPT_CHARMASK('w','o')://wrist open
			use = new MoveWrist(true);
			break;
		case AUTO_SCRIPT_CHARMASK('w','c'):// wrist close
			use = new MoveWrist(false);
			break;
		default:
			break;
		}
		if (use != NULL) {
			switch (cmdType) {
			case 's':
				AddSequential(use);
				break;
			case 'p':
				AddParallel(use);
				break;
			default:
				break;
			}
		}
	}
}
Autonomous::~Autonomous() {
}
void Autonomous::Initialize() {
	//initialize stuffs
}
