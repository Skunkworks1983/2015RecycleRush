#include "Collect.h"

Collect::Collect() {

}

void Collect::Initialize() {
	canCollecterino->induct();
	Requires(canCollecterino);
}

void Collect::Execute() {

}

bool Collect::IsFinished() {
	return canCollecterino->getCanSensor();
}

void Collect::End() {
	canCollecterino->rest();
}

void Collect::Interrupted() {

}
