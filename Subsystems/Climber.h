#ifndef Climber_H
#define Climber_H

#include <Commands/Subsystem.h>
#include <WPILib.h>
class Climber : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	VictorSP* climb;
	bool defined;
public:
	Climber();
	void Init();
	void c();
	void StopClimbing();
	void InitDefaultCommand();
};

#endif  // Climber_H
