#ifndef AutoDrive_H
#define AutoDrive_H

#include <CommandBase.h>

class TimedDrive: public CommandBase {
private:
	double forwardSlashSpeed;
	double backSlashSpeed;
public:
	TimedDrive(float duration, float heading, float speed = AUTO_DRIVE_SPEED);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
