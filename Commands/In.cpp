#include "In.h"

In::In() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::intake.get());
}

// Called just before this Command runs the first time
void In::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void In::Execute() {
	intake->On();
}

// Make this return true when this Command no longer needs to run execute()
bool In::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void In::End() {
	intake->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void In::Interrupted() {
	End();
}
