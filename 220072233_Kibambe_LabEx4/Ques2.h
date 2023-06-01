#pragma once
#include "Ques1.h"
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Transaction {
private:
	int transactionNumber;
	int agentNumber;
	string transactionDate;
protected:
	float transactionAmount;
	float commEarned;
public:
	Transaction();
	Transaction(int, int, string, float, float);
	void enterTransaction();
	void displayTransaction(float);
	float calculateCommEarned(Agent);
	float getCommEarned();
	int getAgentNumber();
};