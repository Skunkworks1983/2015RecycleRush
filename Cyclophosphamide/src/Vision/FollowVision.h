#ifndef FollowVision_H
#define FollowVision_H

#include <CommandBase.h>

class FollowVision: public CommandBase {
private:
	bool neverEnd;
public:
	FollowVision(bool noIsFinished);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
