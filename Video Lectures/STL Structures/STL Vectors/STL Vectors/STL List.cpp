/*
Lists store a linear series of data 
but you cannot randomly access data with the subscript operator[].

To step through a list, you start at the beginning stepping through one at a time.

It does contain a sort() and reverse() function.

STL lists use pointers, keeping track of what it's starting element is
and the current element and next elements.

push_back()
size()
empty()
clear()
sort()
reverse()

*/

#include<iostream>
#include <list>
#include <string>
using namespace std;
int main()
{
	list<string> states;

	states.push_back("Maine");
	states.push_back("Hawaii");
	states.push_back("Kansas");
	states.push_back("Missouri");
	states.push_back("Washington");
	states.push_back("Alaska");

	states.sort();
	states.reverse();


	for (list<string>::iterator it = states.begin(); it != states.end(); it++)
	{
		cout << *it << endl;
	}

	return 0;
}