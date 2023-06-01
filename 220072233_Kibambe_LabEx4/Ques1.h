#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
#include <limits>
using namespace std;

class Agent {

private:
	int agentNumber;
	char agentName[1024];
	float agentTotalComm;

public:
	Agent();
	Agent(int, char[], float);
	Agent(const Agent&);
	void enterAgent();
	void displayAgent();
	int getAgentNumber();
	float getCommission();
	Agent operator+(float);
	Agent operator=(const Agent&);
	bool operator>(Agent&);
};