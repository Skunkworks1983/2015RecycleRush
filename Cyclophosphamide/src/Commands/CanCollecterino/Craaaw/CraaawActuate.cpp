#include <Commands/CanCollecterino/Craaaw/CraaawActuate.h>
#include "CraaawUnactuate.h"

CraaawActuate::CraaawActuate(bool waitForInput) {
	Requires(craaaw);
	this->waitForInput = waitForInput;
}

void CraaawActuate::Initialize() {

}

void CraaawActuate::Execute() {

}

bool CraaawActuate::IsFinished() {
	if(waitForInput){
		if(!craaaw->getCanDetector()){
			craaaw->setActuated(true);
			return true;
		}
	} else {
		craaaw->setActuated(false);
		return true;
	}
	return false;
}

void CraaawActuate::End() {

}

void CraaawActuate::Interrupted() {

}
