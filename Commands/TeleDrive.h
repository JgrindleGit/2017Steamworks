#ifndef TeleDrive_H
#define TeleDrive_H

#include "../CommandBase.h"

class TeleDrive : public CommandBase {
private:
	float kP;
	float kI;
	float kD;
public:
	TeleDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // TeleDrive_H
