#ifndef OI_H
#define OI_H
#include <WPILib.h>
#include "Joystick.h"
//#include "Commands\Climb.h"
class OI {

private:
	Joystick* joy;

public:
	OI();
	Joystick* getJ();
	JoystickButton* cl;
	JoystickButton* sh;

};

#endif  // OI_H
