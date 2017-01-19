#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
	float balance = 0.0;
	// Create a queue of floats, named transactions
	queue<float> transactions;
	
	// Push some + and - floats into the transactions queue.
	transactions.push(12.95);
	transactions.push(-3.99);
	transactions.push(19.95);
	transactions.push(-8.75);
	// Loop through all the transactions - while the queue is empty.
	// Within the loop, whatever amount is at the front of the queue,
	// add it to the balance and then pop it off the queue.
	while (!transactions.empty())
	{
		balance += transactions.front();
		transactions.pop();
	}

	cout << "Final balance: $" << balance << endl;

	return 0;
}