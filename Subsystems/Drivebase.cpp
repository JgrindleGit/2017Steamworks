#include "Drivebase.h"
#include "../RobotMap.h"
//WPILIB DEFINED MAX VALUE
#define max(x, y) (((x) > (y)) ? (x) : (y))


Drivebase::Drivebase() : Subsystem("driveBase") {
	SPEEDM = 17.25;
	SPEEDS = 12.8;
}
void Drivebase::Init(){
	if(!defined){
		rPID = new PID(0.1,0,0);
		lPID = new PID(0.1,0,0);
		sPID = new PID(0.1,0,0);

		dPulse = (((uPI*wheelDia)/12)/360);
		left = new frc::VictorSP(0);
		right = new frc::VictorSP(1);
		sFront = new frc::Spark(2);
		sBack = new frc::Spark(3);

		sEncoder = new frc::Encoder(4,5,false,frc::Encoder::EncodingType::k4X);
		lEncoder = new frc::Encoder(0,1,false,frc::Encoder::EncodingType::k4X);
		rEncoder = new frc::Encoder(3,2,false,frc::Encoder::EncodingType::k4X);

		rEncoder->SetDistancePerPulse(dPulse);
		lEncoder->SetDistancePerPulse(dPulse);
		sEncoder->SetDistancePerPulse(dPulse);

		//gyro = new AnalogGyro(0);
		defined = true;
	}

}
void Drivebase::InitDefaultCommand() {
}
float Drivebase::DzFix(float z, float deadzone){
	if((z >-(deadzone)) && (z < (deadzone))){
		z= 0;
	}
	return z;
}
void Drivebase::SetLeft(float num){
	left->Set(num);
}
void Drivebase::SetRight(float num){
	right->Set(num);
}
void Drivebase::Strafe(float num){
	sFront->Set(num);
	sBack->Set(-num);
}
float Drivebase::constrain(float lower, float num, float high){
	if(num<lower){
		num = lower;
		return num;
	}else if (num> high){
		num = high;
		return num;
	}
	else{
		return num;
	}
}
void Drivebase::NoPID(float Drive,float turn){
	float rVal;
	float lVal;
	if (Drive > 0.0)
	{
		if (turn > 0.0)
		{
			lVal = Drive - turn;
			rVal = max(Drive, turn);
		}
		else
		{
			lVal = max(Drive, -turn);
			rVal = Drive + turn;
		}
	}
	else
	{
		if (turn > 0.0)
		{
			lVal = - max(-Drive, turn);
			rVal = Drive + turn;
		}
		else
		{
			lVal = Drive - turn;
			rVal = - max(-Drive, -turn);
		}
	}
	SetLeft(lVal);
	SetRight(rVal);
}

void Drivebase::DriveTurn(float Drive, float turn, float s){
	float lVal;
	float rVal;
	if (Drive > 0.0)
	{
		if (turn > 0.0)
		{
			lVal = Drive - turn;
			rVal = max(Drive, turn);
		}
		else
		{
			lVal = max(Drive, -turn);
			rVal = Drive + turn;
		}
	}
	else
	{
		if (turn > 0.0)
		{
			lVal = - max(-Drive, turn);
			rVal = Drive + turn;
		}
		else
		{
			lVal = Drive - turn;
			rVal = - max(-Drive, -turn);
		}
	}
	SetSpeedLeft(lVal);
	SetSpeedRight(rVal);
	SetSpeedStrafe(s);
	printf("Lval: %f Rval: %f",lVal,rVal);
}
/*void Drivebase::Move(float Drive, float Turn, float strafe){
	DriveTurn(Drive,Turn);
	Strafe(strafe);
}*/
void Drivebase::Stop(){
	//DriveTurn(0);
	Strafe(0);
	SetLeft(0);
	SetRight(0);
}
void Drivebase::SetSpeedLeft(float speed){
	speed = constrain(-SPEEDM,speed,SPEEDM);
	float lVal = lPID->pid(lEncoder->GetRate(),speed)/SPEEDM;
	/*if((lVal>2.5)||(lVal<-2.5)){
		SetLeft(lVal);
	}else{
		SetLeft(speed/SPEEDM);
	}*/
	SetLeft(lVal);
	printf("left: %f", lVal);
}
void Drivebase::SetSpeedRight(float speed){
	speed = constrain(-SPEEDM, speed, SPEEDM);
	float rVal =rPID->pid(rEncoder->GetRate(),speed)/SPEEDM;
	/*if ((rVal>2.5)||(rVal<-2.5)){
		SetRight(rVal);
	}else{
		SetRight(speed/SPEEDM);
	}*/
	SetRight(rVal);
	printf("right: %f", rVal);

}
void Drivebase::SetSpeedStrafe(float speed){
	speed = constrain(-SPEEDS, speed, SPEEDS);
	float sVal = sPID->pid(sEncoder->GetRate(),speed)/SPEEDS;
	/*if((sVal>2.5)||(sVal<2.5)){
		Strafe(sVal);
	}else{
		Strafe(speed/SPEEDS);
	}*/
	Strafe(sVal);
	printf("Strafe: %f",sVal);
	printf("\n");
}
void Drivebase::SetLPID(float kP,float kI, float kD){
	lPID->setKs(kP,kI,kD);
}
void Drivebase::SetRPID(float kP,float kI, float kD){
	rPID->setKs(kP,kI,kD);
}
void Drivebase::SetSPID(float kP,float kI, float kD){
	sPID->setKs(kP,kI,kD);
}
void Drivebase::StartTime(){
	lPID->TimerStart();
	rPID->TimerStart();
	sPID->TimerStart();
}
void Drivebase::StopTime(){
	lPID->TimerStop();
	rPID->TimerStop();
	sPID->TimerStop();
}
void Drivebase::Reset(){
	lEncoder->Reset();
	rEncoder->Reset();
	sEncoder->Reset();
	lPID->Reset();
	rPID->Reset();
	sPID->Reset();
	//gyro->Reset();
}
float Drivebase::lSpeed(){
	return lEncoder->GetRate();
}
float Drivebase::rSpeed(){
	return rEncoder->GetRate();

}
float Drivebase::sSpeed(){
	return sEncoder->GetRate();
}
float Drivebase::GetKP(){
	return lPID->GetKP();
}
float Drivebase::GetKI(){
	return lPID->GetKI();
}
float Drivebase::GetKD(){
	return lPID->GetKD();
}
float Drivebase::GetAVG(){

	float avg = (((abs(lEncoder->GetDistance()))+(abs(rEncoder->GetDistance())))/2);
	return avg;
}
void Drivebase::DOnePid(float thing){

}


