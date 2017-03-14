#include "AutoDrive.h"

AutoDrive::AutoDrive(float input, float setpoint) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::driveBase.get());
	pid = new PID(3.3,0.7,0.3);
	m_input = input;
	m_setpoint = setpoint;
}

// Called just before this Command runs the first time
void AutoDrive::Initialize() {
	driveBase->SetLPID(0.6,0,0);
	driveBase->SetRPID(0.6,0,0);
	driveBase->SetSPID(0.6,0,0);
	driveBase->Reset();
}

// Called repeatedly when this Command is scheduled to run
void AutoDrive::Execute() {
	//frc::SmartDashboard::PutNumber("AutoError: ",pid->GetError());
	pidO = pid->pid(driveBase->GetAVG(),m_setpoint);
	driveBase->DriveTurn(0,-pidO,0);
	printf("%f",pidO);

}

// Make this return true when this Command no longer needs to run execute()
bool AutoDrive::IsFinished() {
	if((pidO<0.05)&&(pidO>-0.05)){
		return true;
	}else {
		return false;
	}
}

// Called once after isFinished returns true
void AutoDrive::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDrive::Interrupted() {

}
