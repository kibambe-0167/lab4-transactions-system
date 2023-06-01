#pragma once
#include "Ques2.h"
using namespace std;

class SalesTransaction :
	public Transaction
{
private:
	float bondRegistrationFee;
	static float commPerc;

public:
	SalesTransaction();
	static void changeCommissionPerc(float);
	void enterTransaction();
	void displayTransaction();
	void calculateCommEarned(Agent&);
};