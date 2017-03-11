#ifndef PIDEdit_H
#define PIDEdit_H

#include "../CommandBase.h"
#include "../PEdit.h"

class PIDEdit : public CommandBase {
private:
	PEdit* pv;
	bool isKP;
	bool isKI;
	bool isKD;
	float kP;
	float kI;
	float kD;
public:
	PIDEdit();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // PIDEdit_H
