/*
first in first out

push() - pushes to the back
pop() - removes front
front() - returns front
size()
empty()

*/


#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
	queue<string> commands;

	commands.push("mkdir newFolder");
	commands.push("touch newFile");
	commands.push("ping google.com -c 5");
	commands.push("ping yahoo.com -c 3");

	while (!commands.empty())
	{
		string command = commands.front();

		cout << endl << command << endl;

		//system( command.c_str() );
		
		commands.pop();
	}

	return 0;
}