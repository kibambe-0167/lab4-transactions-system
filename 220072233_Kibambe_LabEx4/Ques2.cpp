#include "Ques2.h"

Transaction::Transaction() {
	transactionNumber = 0;
	agentNumber = 0;
	transactionAmount = 0;
	commEarned = 0;
}

Transaction::Transaction(int trans_num, int agent_num, string date, float trans_amount, float comm_earned) {
	transactionNumber = trans_num;
	agentNumber = agent_num;
	transactionDate = date;
	transactionAmount = trans_amount;
	commEarned = comm_earned;
}
void Transaction::enterTransaction() {
	cout << endl << "Enter transaction number :";
	cin >> transactionNumber;
	cout << "date 04/08/2005 : ";
	cin >> transactionDate;
	cout << "transaction amount : ";
	cin >> transactionAmount;
	cout << "agent number : ";
	cin >> agentNumber;
}
void Transaction::displayTransaction(float comm_earned) {
	cout << endl << "Transaction: " << transactionNumber << "  Agent number" << agentNumber
		<< "  Date: " << transactionDate << "  Price: " << transactionAmount << "  Commission Earned: " << comm_earned <<endl;
}

float Transaction::calculateCommEarned(Agent) {
	return commEarned;
}

float Transaction::getCommEarned() {
	return commEarned;
}

int Transaction::getAgentNumber() {
	return agentNumber;
}