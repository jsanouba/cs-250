/*
the index are called keys and these keys don't have to be integers.
they can be any data type and can point to a value of any data type.

operator[] - access an element of the map using a key
insert()
empty()
size()

*/

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	/*
	string employees[3];
	employees[0] = "Harry";
	employees[1] = "Ron";
	employees[2] = "Hermione";

	cout << "Employee 0 is " << employees[0] << endl;
	*/

	map<int, string> employees; 
	employees[1024] = "Harry";
	employees[256] = "Ron";
	employees[512] = "Hermione";

	int key;
	cout << "Enter an employee ID: ";
	cin >> key;

	cout << "That employee is " << employees[key] << endl;

	return 0;
}