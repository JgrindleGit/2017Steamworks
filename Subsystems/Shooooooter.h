#ifndef Shooooooter_H
#define Shooooooter_H

#include <Commands/Subsystem.h>
#include <WPILib.h>
class Shooooooter : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	VictorSP* shoot;
	bool defined;
public:
	Shooooooter();
	void Init();
	void InitDefaultCommand();
	void Shoot();
	void Stop();
};

#endif  // Shooooooter_H
