#ifndef FollowVision_H
#define FollowVision_H

#include <CommandBase.h>

class FollowVision: public CommandBase {
public:
	FollowVision();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
