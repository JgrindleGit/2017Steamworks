#ifndef AutoDrive_H
#define AutoDrive_H

#include "../CommandBase.h"

class AutoDrive : public CommandBase {
public:
	AutoDrive(float, float);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	PID* pid;
	float pidO;
	float m_input;
	float m_setpoint;
};

#endif  // AutoDrive_H
