#include <Commands/AutoCanCollecterino/Wencherino.h>

Wencherino::Wencherino(AutoCanerinoPuck::WenchSetting winchSetting) {
	switch(winchSetting) {
		case AutoCanerinoPuck::WenchSetting::bringIn:
			setPoint = AUTO_CAN_PULL_DIST;
			pull = true;
			break;
		case AutoCanerinoPuck::WenchSetting::letDown:
			setPoint = AUTO_CAN_LET_DOWN;
			pull = false;
			break;
		case AutoCanerinoPuck::WenchSetting::putBack:
			setPoint = AUTO_CAN_PUT_BACK;
			pull = false;
			break;
	}
}

void Wencherino::Initialize() {
	autoCanerinoPuck->wenchSet(pull);
}

void Wencherino::Execute() {

}

bool Wencherino::IsFinished() {
	return autoCanerinoPuck->wenchGetPosition() == setPoint;
}

void Wencherino::End() {
	autoCanerinoPuck->wenchStop();
}

void Wencherino::Interrupted() {

}
