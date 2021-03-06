#include "OI.h"
#include "Commands/Climb.h"
#include "Commands/In.h"
#include "Commands/Shoot.h"

OI::OI() {
	// Process operator interface input here.
	joy = new Joystick(0);

	cl = new JoystickButton(joy,11);
	cl->WhileHeld(new Climb());
	sh = new JoystickButton(joy,12);
	sh->WhileHeld(new Shoot());
	in = new JoystickButton(joy,10);
	in->WhileHeld(new In());
}

Joystick* OI::getJ(){
	return (joy);
}
