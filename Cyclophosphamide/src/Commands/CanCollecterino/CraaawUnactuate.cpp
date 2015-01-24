#include <Commands/CanCollecterino/CraaawUnactuate.h>
#include "CraaawActuate.h"

CraaawUnactuate::CraaawUnactuate() {

}

void CraaawUnactuate::Initialize() {
	Requires(craaaw);

}

void CraaawUnactuate::Execute() {

}

bool CraaawUnactuate::IsFinished() {
	return oi->getUnactuate();
}

void CraaawUnactuate::End() {
	craaaw->toggle();
	new CraaawActuate();
}

void CraaawUnactuate::Interrupted() {

}
