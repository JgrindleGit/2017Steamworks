/*
 * PEdit.h
 *
 *  Created on: Mar 8, 2017
 *      Author: John
 */

#ifndef SRC_PEDIT_H_
#define SRC_PEDIT_H_

class PEdit
{
public:
	PEdit();
	void ChangeKUp();
	void ChangeKDown();

	void ChangeVUp();
	void ChangeVDown();

	int GetSel();

	float getPVal();
	float getIVal();
	float getDVal();

private:
	bool kS [3] = {true,false,false};
	float kP;
	float kI;
	float kD;
};




#endif /* SRC_PEDIT_H_ */
