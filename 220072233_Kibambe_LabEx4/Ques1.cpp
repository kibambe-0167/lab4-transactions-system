#include "Ques1.h"

Agent::Agent() {
	agentTotalComm = 0;
	agentNumber = 0;
	strcpy_s(agentName, " ");
}

Agent::Agent(const Agent& other)
	: agentNumber(other.agentNumber), agentTotalComm(other.agentTotalComm) {
	strncpy_s(agentName, other.agentName, sizeof(agentName) - 1);
}

Agent::Agent(int num, char names[], float comm) {
	agentTotalComm = comm;
	agentNumber = num;
	strcpy_s(agentName, names);
}

void Agent::enterAgent() {
	string names;
	cout << endl<< "Enter agent names: ";
	getline(cin, names);
	// cin.clear();

	cout << "Enter agent number: ";
	cin >> agentNumber;
	strcpy_s(agentName, names.c_str());
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Agent::displayAgent() {
	cout << endl << endl;
	cout << "Agent:" << agentNumber << "  " << agentName << "  Total Commission Earned : R" << agentTotalComm << endl;
}

int Agent::getAgentNumber() {
	return agentNumber;
}

float Agent::getCommission() {
	return agentTotalComm;
}

Agent Agent::operator+(float comm) {
	Agent temp;
	strcpy_s(temp.agentName, agentName);
	temp.agentTotalComm = agentTotalComm + comm;
	temp.agentNumber = agentNumber;
	return temp;
}

bool Agent::operator>(Agent& agent) {
	if (agentTotalComm > agent.agentTotalComm) return true;
	else return false;
}

Agent Agent::operator=(const Agent& agent) {
	Agent t;
	t.agentNumber = agent.agentNumber;
	strcpy_s(t.agentName, agent.agentName);
	t.agentTotalComm = agent.agentTotalComm;
	return t;
}