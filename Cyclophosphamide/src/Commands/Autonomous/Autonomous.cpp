#include "Autonomous.h"

Autonomous::Autonomous() :
		CommandGroup("Autonomous-Blank") {
}

Autonomous::Autonomous(char *style) :
		CommandGroup(style) {
}

Autonomous::~Autonomous() {

}

void Autonomous::Initialize(){
}
