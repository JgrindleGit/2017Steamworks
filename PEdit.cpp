/*
 * PEdit.cpp
 *
 *  Created on: Mar 8, 2017
 *      Author: John
 */
#include "PEdit.h"

PEdit::PEdit(){
	//bool kS[] = {true,false,false};
	kP = 0.1;
	kI = 0;
	kD = 0;
}
void PEdit::ChangeVUp(){
	if(kS[0] == true){
		kS[0] = false;
		kS[1] = true;
	}else if (kS[1] == true){
		kS[1] = false;
		kS[2] = true;
	}

}
void PEdit::ChangeKUp(){
	int Sel = GetSel();
	switch(Sel){
	case 1:
		kP += .05;
		break;
	case 2:
		kI += .05;
		break;
	case 3:
		kD += .05;
		break;
	default:
		break;

	}
}
void PEdit::ChangeVDown(){
	if(kS[1] == true){
		kS[0] = true;
		kS[1] = false;
	}else if (kS[2] == true){
		kS[1] = true;
		kS[2] = false;
	}
}
void PEdit::ChangeKDown(){
	int Sel = GetSel();
	switch(Sel){
	case 1:
		kP -= .05;
		break;
	case 2:
		kI -= .05;
		break;
	case 3:
		kD -= .05;
		break;
	}
}

int PEdit::GetSel(){
	if(kS[0] == true){
		return 1;
	}else if (kS[1] ==true){
		return 2;
	}else if(kS[2] ==true){
		return 3;
	}

}
float PEdit::getPVal(){
	return kP;
}
float PEdit::getIVal(){
	return kI;
}
float PEdit::getDVal(){
	return kD;
}


