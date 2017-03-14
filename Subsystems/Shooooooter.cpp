#include "Shooooooter.h"
#include "../RobotMap.h"

Shooooooter::Shooooooter() : Subsystem("ExampleSubsystem") {

}
void Shooooooter::Init(){
	if(!defined){
		shoot = new frc::VictorSP(5);
		defined = true;
	}
}
void Shooooooter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}
void Shooooooter::Shoot(){
	shoot->Set(-.87);
}
void Shooooooter::Stop(){
	shoot->Set(0);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
