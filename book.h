#include <string>
#include <iostream>
using namespace std;

#include "libraryitem.h"

class Book : public LibraryItem 
{
	public:
		// Default 
		Book();
		// Muatators 
		void SetTitle(string bookTitle);
		void SetAuthor(string bookAuthor);
		void SetISBN(int bookISBN);
		void PrintInfo() override;
		void PrintRawInfo() override;
		// Accessors 
		string GetTitle();
		string GetAuthor();
		int GetISBN();
	private:
		string bookTitle;
		string bookAuthor;
		int bookISBN;
};
