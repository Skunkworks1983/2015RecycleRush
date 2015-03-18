#include <Commands/CanCollecterino/IndexTote.h>

IndexTote::IndexTote() {
	AddSequential(new Induct(Induct::reverse, 0.1));
	AddSequential(new Induct(Induct::forward, 0.15));
}
