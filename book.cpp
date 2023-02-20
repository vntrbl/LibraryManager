#include <string>
#include <fstream> 
#include <iostream>
using namespace std;

#include "book.h"

// Default 
Book::Book()
{
	bookTitle = "none";
	bookAuthor = "none";
	bookISBN = 0;
}
// Mutators 
void Book::SetTitle(string bookTitle)
{
	this->bookTitle = bookTitle;
}
void Book::SetAuthor(string bookAuthor)
{
	this->bookAuthor = bookAuthor;
}
void Book::SetISBN(int bookISBN)
{
	this->bookISBN = bookISBN;
}
// Function: Outputs book information 
void Book::PrintInfo()
{
	cout << "ITEM ID: " << GetItemID() << " | " << "COST: $" << GetItemCost();
	cout << " | " << "MAX LOAN PERIOD: " << GetLoanPeriod() << " | " << "STATUS: " << GetItemStatus();
	cout << " | " << "TITLE: " << GetTitle() << " | " << "AUTHOR: " << GetAuthor() << " | ";
	cout << "ISBN: " << GetISBN() << endl << endl; 
}
// Function: Saves book information 
void Book::PrintRawInfo()
{
	int num = 1;
	
	ofstream fout("items.dat" , ios::app);
	fout << num << endl << GetItemID() << endl << GetItemCost() << endl << GetLoanPeriod() << endl;
	fout << GetItemStatus() << endl << GetTitle() << endl << GetAuthor() << endl << GetISBN() << endl; 
	fout.close();
}
// Accessors 
string Book::GetTitle()
{
	return bookTitle;
}
string Book::GetAuthor()
{
	return bookAuthor;
}
int Book::GetISBN()
{
	return bookISBN;
}
