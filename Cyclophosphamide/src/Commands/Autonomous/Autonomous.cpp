#include "Autonomous.h"
#include "../Automatic/BestDrive.h"

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
		case AUTO_SCRIPT_CHARMASK('d', 'd'):
			//use = new BestDrive(arg);
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
