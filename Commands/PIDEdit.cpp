#include "PIDEdit.h"

PIDEdit::PIDEdit() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	//Requires(driveBase.get());
	pv = new PEdit();
	kP = pv->getPVal();
	kI = pv->getIVal();
	kD = pv->getDVal();

}

// Called just before this Command runs the first time
void PIDEdit::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void PIDEdit::Execute() {
	frc::SmartDashboard::PutNumber("Top", oi->getJ()->GetTop());
	switch(oi->getJ()->GetTop()){
	case 360:
		pv->ChangeKUp();
		break;
	case 90:
		pv->ChangeVUp();
		break;
	case 180:
		pv->ChangeKDown();
		break;
	case 270:
		pv->ChangeVDown();
		break;
	default:
		break;
	}
	switch(pv->GetSel()){
	case 1:
		isKP = true;
		isKI = false;
		isKD = false;
	case 2:
		isKP = false;
		isKI = true;
		isKD = false;
	case 3:
		isKP = false;
		isKI = false;
		isKD = true;
	default: break;
	}
	kP = pv->getPVal();
	kI = pv->getIVal();
	kD = pv->getDVal();
	frc::SmartDashboard::PutBoolean("p",isKP);
	frc::SmartDashboard::PutBoolean("i",isKI);
	frc::SmartDashboard::PutBoolean("d",isKD);
	frc::SmartDashboard::PutNumber("kP", kP);
	frc::SmartDashboard::PutNumber("kI", kI);
	frc::SmartDashboard::PutNumber("kD", kD);
}

// Make this return true when this Command no longer needs to run execute()
bool PIDEdit::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void PIDEdit::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PIDEdit::Interrupted() {

}
