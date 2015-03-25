#ifndef AutoDrive_H
#define AutoDrive_H

#include <CommandBase.h>

class TimedDrive: public CommandBase {
private:
	double speed;
	DriveBae::MotorSide side;
	bool test;
public:
	TimedDrive(float duration, float speed, DriveBae::MotorSide side = DriveBae::MotorSide::FRONT_LEFT, bool test = false);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
