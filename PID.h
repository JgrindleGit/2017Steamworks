/*
 * PID.h
 *
 *  Created on: Mar 8, 2016
 *      Author: John
 */

#ifndef SRC_PID_H_
#define SRC_PID_H_
#include "WPILib.h"
#include "Timer.h"
class PID
{

private:
	Timer* timer;
	float integral;
	float tim;
	float prevErr;
	float prop;
	float derivative;
	float out;
	float kP;
	float kI;
	float kD;
	//float err;
public:
	PID();
	PID(float, float, float);
	float pid(float des, float cur);
	void setKs(float kp, float ki, float kd);
	float error(float initial, float var);
	float dzFix(float z, float deadzone);
	void TimerStart();
	void TimerStop();
	void Reset();
	//float GetError();
	float GetKP();
	float GetKI();
	float GetKD();

};


#endif /* SRC_PID_H_ */
