#ifndef SCORE_LINEUP_H
#define SCORE_LINEUP_H

#include "../../CommandBase.h"
#include "WPILib.h"

class ScoreLineup: public CommandBase {
public:
	ScoreLineup();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
