#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include <vector>

void LoadPages(vector<string>& pages, const string& filename)
{
	ifstream input(filename);
	string line;
	string pageText = "";
	int lineCount = 0;
	int pageCount = 0;

	while (getline(input, line))
	{
		pageText = pageText + "\n" + line;

		lineCount++;
		if (lineCount == 27)
		{
			// Add page to book now
			pages.push_back(pageText);
			pageCount++;

			// Reset the page text
			pageText = "";

			// Reset the line count
			lineCount = 0;
		}

		if (pageCount == 100)
		{
			// The book is full! Can't load any more.
			cout << "The book is full! Can't load any more.\n";
			return;
		}
	}

	input.close();
}

void ReadBook(vector<string>& pages)
{
	int currentPage = 0;
	int totalPages = 100;

	bool done = false;

	while (!done)
	{
		cout << pages[currentPage] << endl;
		cout << "--- PAGE " << currentPage + 1 << " OF " << totalPages << "---------------------------------" << endl;
		cout << "(N)ext Page, (P)revious Page, (Q)uit" << endl;
		cout << ">> ";
		string choice;
		cin >> choice;

		if (choice == "Q" || choice == "q") 
		{ 
			done = true; 
		}
		else if (choice == "N" || choice == "n")
		{
			if (currentPage + 1 < totalPages)
			{
				currentPage++;
			}
		}
		else if (choice == "P" || choice == "p")
		{
			if (currentPage - 1 >= 0)
			{
				currentPage--;
			}
		}
	}
}

int main()
{
	vector<string> pages;

	LoadPages(pages, "Aesop.txt");
	ReadBook(pages);

	return 0;
}