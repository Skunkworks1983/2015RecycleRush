#include "Autonomous.h"
#include "../Automatic/BestDrive.h"
#include "../Automatic/TurnTo.h"

Autonomous::Autonomous() :
		CommandGroup("Autonomous-Blank") {
}
Autonomous::Autonomous(char *style) :
		CommandGroup(style) {
}

Autonomous::~Autonomous() {
}
