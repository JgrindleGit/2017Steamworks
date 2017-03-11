/*
 * PID.cpp
 *
 *  Created on: Feb 11, 2017
 *      Author: John
 */
#include "PID.h"


PID::PID(){

	kP = 0.1;
	kI = 0;
	kD = 0;
	timer = new frc::Timer();
	prevErr = 0;
	tim =0;
	integral = 0;
}
PID::PID(float kp, float ki, float kd)
{
	kP = kp;
	kI = ki;
	kD = kd;
	timer = new frc::Timer();
	prevErr = 0;
	tim =0;
	integral = 0;
}
void PID::setKs(float kp, float ki, float kd)
{
	kP = kp;
	kI = ki;
	kD = kd;
}
float PID::pid(float des, float cur)
{
	float err = error(des, cur);
	prop = err * kP;
	integral = (err+prevErr)*kI;
	derivative = (err - prevErr)*kD;
	out = (prop + integral + derivative);
	prevErr = err;
	return out;
	//tim -= float(timer->Get());
}
float PID::error(float initial, float var)
{
	float err;
	err = (initial-var);
	return err;
}
float PID::dzFix(float z, float deadzone)
{
	if((z >-(deadzone)) && (z < (deadzone))){
			z = 0;
		}
	return z;
}
void PID::TimerStart(){
	timer->Start();
}
void PID::TimerStop(){
	timer->Stop();
}
void PID::Reset(){
	timer->Reset();
	integral = 0;
	prop = 0;
	derivative =0;
	prevErr = 0;

}
float PID::GetKP(){
	return kP;
}
float PID::GetKI(){
	return kI;
}

float PID::GetKD(){
	return kD;
}
