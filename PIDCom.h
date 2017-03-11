/*
 * PIDCom.h
 *
 *  Created on: Mar 11, 2017
 *      Author: John
 */

#ifndef PIDCOM_H_
#define PIDCOM_H_

#include "WPILib.h"
#include "PID.h"

class PIDCom : public Command {

public:
	PIDCom();
	PIDCom(Encoder &input,float target,float p, float i, float d);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();



private:
	PID* pid;

};




#endif /* PIDCOM_H_ */
