#include "Ques2.h"
#include "Ques3.h"
#include "Ques4.h"

int main() {
	const int num_agents = 3;
	const int num_trans_enter = 2;
	// Set the commission percentage of all SalesTransactions to 7.5%.
	SalesTransaction::changeCommissionPerc(7.5);

	// Set the commission percentage of all RentalTransactions to 4%.
	RentalTransaction::changeCommissionPerc(4);

	// Create an array of three Agents, an array of 10 
	// SalesTransactions and an array of 10 RentalTransactions.
	Agent agents_array[num_agents];
	SalesTransaction sales_array[10];
	RentalTransaction rentals_array[10];

	// Enter information for the three Agents
	for (int i = 0; i < num_agents; i++) 
		agents_array[i].enterAgent();

	// Enter at least four SalesTransactions, with one of the three 
	// Agents handling the transaction for each, also using a loop.
	cout << endl << endl<< " --- Sales Transactions --- " << endl;
	for (int i = 0; i < num_trans_enter; i++) {
		sales_array[i].enterTransaction();
		sales_array[i].calculateCommEarned(agents_array[0]);
	}

	// Enter at least four RentalTransactions, with one of the 
	// three Agents handling the transaction for each, also using a loop.
	cout << endl<< endl << " --- Rental Transactions --- " << endl;
	for (int i = 0; i < num_trans_enter; i++) {
		rentals_array[i].enterTransaction();
		rentals_array[i].calculateCommEarned(agents_array[1]);
	}

	// Calculate the commission earned on all the transactions.
	float all_transactions = 0;
	for (int r = 0; r < num_trans_enter; r++) {
		all_transactions += rentals_array[r].getCommEarned();
		all_transactions += sales_array[r].getCommEarned();
	}
	cout << endl << endl << " --- Commission Earned On All Transactions: "
		<< all_transactions << " --- " << endl << endl;

	// Using nested loops, accumulate the commission earned by each Agent by doing
	// the following : If the agent number of the current Agent object is the same as the
	// agent number of the transaction, then add the commission earned to the
	// particular Agent object. (Remember to apply both types of transactions).While
	// in the loop, print each Agent’s payslip(see format below).
	Agent agents_total_comm[num_agents];
	for (int a = 0; a < num_agents; a++) {
		for (int r = 0; r < num_trans_enter; r++) {
			if (agents_array[a].getAgentNumber() == rentals_array[r].getAgentNumber()) {
				agents_total_comm[a] = agents_array[a] + rentals_array[r].getCommEarned();
				rentals_array[r].displayTransaction();
			}
			if (agents_array[a].getAgentNumber() == sales_array[r].getAgentNumber()) {
				agents_total_comm[a] = agents_array[a] + sales_array[r].getCommEarned();
				sales_array[r].displayTransaction();
			}
		}
	}

	// By using this object and arrow notation, determine and display
	// the agent of the month(i.e.the one that earned the highest total commission).
	Agent found_agent;
	for (int a = 0; a < num_agents; a++) {
		// agents_total_comm[a].displayAgent();
		if (agents_total_comm[a] > found_agent )
			found_agent = agents_total_comm[a];
	}

	found_agent.displayAgent();

	cout << endl << endl << " --- dynamic agent --- ";
	// Dynamically create an object of type Agent.
	Agent* dynamic_agent = new Agent(found_agent);
	dynamic_agent->displayAgent();

	//Remove the dynamically created object from memory.
	delete dynamic_agent;
	dynamic_agent = nullptr;

	return 0;
}
