#include <Commands/CanCollecterino/PutUp.h>
#include "Arms/MoveArms.h"
PutUp::PutUp() {
	AddSequential(new MoveArms(true));
//	AddSequential(new );
}
