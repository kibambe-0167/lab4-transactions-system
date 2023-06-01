#include "Ques4.h"

float RentalTransaction::commPerc = 0;

RentalTransaction::RentalTransaction() {
	commPerc = 0;
	rentalPeriod = 0;
}

void RentalTransaction::changeCommissionPerc(float value) {
	commPerc = value;
}

void RentalTransaction::enterTransaction() {
	Transaction::enterTransaction();
	cout << "rental period (in months) :";
	cin >> rentalPeriod;
}

void RentalTransaction::displayTransaction() {
	Transaction::displayTransaction(Transaction::getCommEarned());
	cout << "Commission earned on this rental transaction : " << Transaction::getCommEarned() << endl;
}

void RentalTransaction::calculateCommEarned(Agent& agent) {
	if (Transaction::getAgentNumber() == agent.getAgentNumber())
		Transaction::commEarned = (commPerc * Transaction::transactionAmount) * rentalPeriod;
	else Transaction::commEarned = 0;
}