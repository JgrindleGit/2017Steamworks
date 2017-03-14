#include "Intake.h"
#include "../RobotMap.h"

Intake::Intake() : Subsystem("ExampleSubsystem") {

}

void Intake::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}
void Intake::Init(){
	if(!defined){
		in = new frc::VictorSP(6);
		defined = true;
	}
}

void Intake::On(){
	in->Set(1);
}
void Intake::Stop(){
	in->Set(0);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
