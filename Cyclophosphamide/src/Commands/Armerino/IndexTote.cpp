#include <Commands/Armerino/IndexTote.h>

IndexTote::IndexTote() {
	AddSequential(new Induct(Induct::reverse, 0.1, Induct::tote));
	AddSequential(new Induct(Induct::forward, 0.15, Induct::tote));
}
