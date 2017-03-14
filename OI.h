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
	JoystickButton* in;

};

#endif  // OI_H
