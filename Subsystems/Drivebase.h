#ifndef Drivebase_H
#define Drivebase_H


#include <Commands/Subsystem.h>
#include <WPILib.h>
#include "../PID.h"

class Drivebase : public Subsystem {
private:
	//AnalogGyro* gyro;
	VictorSP* left;
	VictorSP* right;
	Spark* sFront;
	Spark* sBack;
	Encoder* lEncoder;
	Encoder* rEncoder;
	Encoder* sEncoder;
	PID* rPID;
	PID* lPID;
	PID* sPID;
	double dPulse;
	bool defined;
	float SPEEDM;
	float SPEEDS;
public:
	Drivebase();
	void InitDefaultCommand();
	float constrain(float,float,float);
	void SetLeft(float);
	void SetRight(float);
	void Strafe(float);
	void DriveTurn(float,float, float);
	//void Move(float,float,float);
	void Stop();
	void Reset();
	void SetSpeedLeft(float);
	void SetSpeedRight(float);
	void SetSpeedStrafe(float);
	void SetLPID(float,float,float);
	void SetRPID(float,float,float);
	void SetSPID(float,float,float);
	void StartTime();
	void StopTime();
	void Init();
	void NoPID(float,float);
	float rSpeed();
	float lSpeed();
	float sSpeed();
	float DzFix(float,float);
	float GetKP();
	float GetKI();
	float GetKD();

};

#endif  // Drivebase_H
