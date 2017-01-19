#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class Book
{
public:
	Book(const string& title)
	{
		m_title = title;
		m_checkedIn = false;
	}

	void CheckIn()
	{
		cout << "Checked in \"" << m_title << "\"" << endl;
		m_checkedIn = true;
	}

private:
	string m_title;
	bool m_checkedIn;
};

int main()
{
	// Create a stack of Book objects called bookDrop.
	stack<Book> bookDrop;

	// Push a series of books into the bookDrop.
	bookDrop.push( Book("Harry Potter and the Goblet of Fire") ) ;
	bookDrop.push( Book("Twilight") );
	bookDrop.push( Book("Hatchet") );
	bookDrop.push( Book("Memoirs of a Geisha") );


	vector<Book> bookPool;

	// Go through the stack of books using a while loop,
	// while the stack is not empty...
	// Take the top-most book, and push it into the bookPool.
	// Then pop the top book off the bookDrop.
	while (!bookDrop.empty())
	{
		bookDrop.top().CheckIn();
		bookPool.push_back( bookDrop.top() );
		bookDrop.pop();
	}

	return 0;
}