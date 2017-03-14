#include "TeleDrive.h"

#define SPEEDS 12.3
#define SPEEDM 16

TeleDrive::TeleDrive() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::driveBase.get());


}

// Called just before this Command runs the first time
void TeleDrive::Initialize() {
	driveBase->SetLPID(1.5,0.2,0);
	driveBase->SetRPID(1.5,0.2,0);
	driveBase->SetSPID(1,0,0);
	driveBase->Reset();
	frc::DriverStation::ReportError("Russians have found IP");

}

// Called repeatedly when this Command is scheduled to run
void TeleDrive::Execute() {
	kP= driveBase->GetKP();
	kI= driveBase->GetKI();
	kD= driveBase->GetKD();

	frc::SmartDashboard::PutNumber("LSpeed",driveBase->lSpeed());
	frc::SmartDashboard::PutNumber("RSpeed",driveBase->rSpeed());
	frc::SmartDashboard::PutNumber("SSpeed",driveBase->sSpeed());

	float drive = driveBase->DzFix(oi->getJ()->GetRawAxis(2),0.04);
	float turn = driveBase->DzFix(oi->getJ()->GetRawAxis(1),0.04);
	float strafe = driveBase->DzFix(oi->getJ()->GetRawAxis(0),0.04);
	turn = turn*(SPEEDM);
	drive = (drive*SPEEDS/2);
	strafe = strafe*SPEEDS;
	frc::SmartDashboard::PutNumber("kP: ", kP);
	frc::SmartDashboard::PutNumber("kI: ", kI);
	frc::SmartDashboard::PutNumber("kD: ", kD);

	//if ((abs(drive)>0.05)&&(abs(turn)>0.05)&&(abs(strafe)>0.05)){
		driveBase->DriveTurn(-drive,-turn,strafe);
	//}
}

// Make this return true when this Command no longer needs to run execute()
bool TeleDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TeleDrive::End() {
	driveBase->Reset();
	driveBase->Stop();
	driveBase->StopTime();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TeleDrive::Interrupted() {

}
