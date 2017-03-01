#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int myNumbers[3];
	myNumbers[0] = 2;
	myNumbers[1] = 3;
	myNumbers[2] = 6;
	
	for (int i = 0; i < 3; i++)
	{
		cout << i << "\t" << myNumbers[i] << endl;
	}

	vector<int> myNumbers2;
	myNumbers2.push_back(2);
	myNumbers2.push_back(3);
	myNumbers2.push_back(6);

	myNumbers2[0] = 1;

	for (unsigned int i = 0; i < myNumbers2.size(); i++)
	{
		cout << i << "\t" << myNumbers2[i] << endl;
	}

	return 0;
}