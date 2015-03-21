#include <Commands/Armerino/IndexTote.h>

IndexTote::IndexTote() {
	AddSequential(new Induct(TOTE_EXPEL_SPEED, 0.1));
	AddSequential(new Induct(TOTE_INDEX_SPEED, 0.15));
}
