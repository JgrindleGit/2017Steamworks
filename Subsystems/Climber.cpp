#include "Climber.h"
#include "../RobotMap.h"

Climber::Climber() : Subsystem("climber") {
}
void Climber::Init(){
	if(!defined){
		climb = new frc::VictorSP(4);
		defined = true;
	}
}

void Climber::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}
void Climber::c(){
	climb->Set(1);
}
void Climber::StopClimbing(){
	climb->Set(0);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
