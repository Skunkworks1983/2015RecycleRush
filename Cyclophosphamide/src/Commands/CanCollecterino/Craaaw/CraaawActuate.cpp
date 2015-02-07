#include <Commands/CanCollecterino/Craaaw/CraaawActuate.h>
#include "CraaawUnactuate.h"

CraaawActuate::CraaawActuate() {

}

void CraaawActuate::Initialize() {
	Requires(craaaw);

}

void CraaawActuate::Execute() {

}

bool CraaawActuate::IsFinished() {
	return craaaw->getCanDetector();
}

void CraaawActuate::End() {
	craaaw->toggle();
	new CraaawUnactuate();
}

void CraaawActuate::Interrupted() {

}
