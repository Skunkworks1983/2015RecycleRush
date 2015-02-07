#include <Commands/AutoCanCollecterino/Wencherino.h>

Wincherino::Wincherino(AutoCanerinoPuck::WinchSetting winchSetting) {
	switch(winchSetting) {
		case AutoCanerinoPuck::WinchSetting::bringIn:
			setPoint = AUTO_CAN_PULL_DIST;
			pull = true;
			break;
		case AutoCanerinoPuck::WinchSetting::letDown:
			setPoint = AUTO_CAN_LET_DOWN;
			pull = false;
			break;
		case AutoCanerinoPuck::WinchSetting::putBack:
			setPoint = AUTO_CAN_PUT_BACK;
			pull = false;
			break;
	}
}

void Wincherino::Initialize() {
	autoCanerinoPuck->wenchSet(pull);
}

void Wincherino::Execute() {

}

bool Wincherino::IsFinished() {
	return autoCanerinoPuck->wenchGetPosition() == setPoint;
}

void Wincherino::End() {
	autoCanerinoPuck->wenchStop();
}

void Wincherino::Interrupted() {

}
