#include "Ques3.h"


float SalesTransaction::commPerc = 0;

SalesTransaction::SalesTransaction() {
	bondRegistrationFee = 0;
	commPerc = 0;
}

void SalesTransaction::changeCommissionPerc(float perc) {
	commPerc = perc;
}

void  SalesTransaction::enterTransaction() {
	Transaction::enterTransaction();
	cout << "bond registration fee :";
	cin >> bondRegistrationFee;
}

void SalesTransaction::displayTransaction() {
	Transaction::displayTransaction(Transaction::getCommEarned());
	cout << "Commission earned on this sales transaction : " << Transaction::getCommEarned() << endl;
}

void SalesTransaction::calculateCommEarned(Agent& agent) {
	if (Transaction::getAgentNumber() != agent.getAgentNumber())  Transaction::commEarned = 0;
	else Transaction::commEarned = (commPerc * Transaction::transactionAmount) - bondRegistrationFee;
}