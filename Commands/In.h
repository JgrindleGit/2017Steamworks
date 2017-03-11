#ifndef In_H
#define In_H

#include "../CommandBase.h"

class In : public CommandBase {
public:
	In();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // In_H
