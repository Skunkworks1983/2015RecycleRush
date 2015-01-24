#include "Collect.h"

Collect::Collect() {

}

void Collect::Initialize() {
	canCollecterino->induct();
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
