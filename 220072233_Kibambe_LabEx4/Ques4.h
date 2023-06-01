#pragma once
#include "Ques2.h"

class RentalTransaction
	: public Transaction {
public:
	int rentalPeriod;

protected:
	static float commPerc;

public:
	RentalTransaction();
	static void changeCommissionPerc(float);
	void enterTransaction();
	void displayTransaction();
	void calculateCommEarned(Agent&);
};