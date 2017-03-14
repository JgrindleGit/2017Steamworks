#ifndef Intake_H
#define Intake_H

#include <Commands/Subsystem.h>
#include "WPIlib.h"
class Intake : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	VictorSP* in;
	bool defined;
public:
	Intake();
	void InitDefaultCommand();
	void On();
	void Init();
	void Stop();
};

#endif  // Intake_H
