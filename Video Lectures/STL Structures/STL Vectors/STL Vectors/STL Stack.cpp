/*
Stack is linear but restricts access to the internal data.
It's a Last In First Out structure. So you're only able to
access the top-most item.

pop() removes the top-most item, so kind of like undoing a turn in tic-tac-toe
push() - pushes item to top of stack
top() - returns item that's at the top
size()
empty()

*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() 
{
	string text;
	cout << "Enter some text: ";
	cin >> text;

	stack<char> letters;
	for (unsigned int i = 0; i < text.size(); i++)
	{
		cout << "Letter " << i << " = " << text[i] << endl;
		letters.push(text[i]);
	}

	cout << endl << "Pop off stack: " << endl;

	while (!letters.empty())
	{
		cout << letters.top();
		letters.pop();
	}

	cout << endl << endl;

	stack<string> states;

	states.push("Alaska");
	states.push("Alabama");
	states.push("Hawaii");
	states.push("Kansas");
	states.push("Missouri");
	states.push("Oklahoma");

	while (!states.empty())
	{
		cout << states.top() << endl;
		states.pop();
	}

	return 0;
}
