// Van Cung
// CSCE 10240
// Homework #4

#include <time.h>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <iostream>
using namespace std;

#include "patrons.h"

// Add Patron w/ info 
void Patrons::AddPatron()
{ 
	string name;
	Patron patron;
	
	srand(time(0));
	
	cout << "Enter Patron Name: ";
	getline(cin, name);
	
	patron.SetID(rand() % 100000 + 100000);
	patron.SetName(name);
	patron.SetFineBal(0.0);
	patron.SetBooksOut(0);
	
	patronList.push_back(patron);
}
// Books out + 1
void Patrons::EditPatron1(int i)
{
	int newBooksOut = patronList.at(i).GetBooksOut1() + 1;
	patronList.at(i).SetBooksOut(newBooksOut);
}
// Books out - 1
void Patrons::EditPatron2(int id)
{
	int newBooksOut = patronList.at(id).GetBooksOut1() - 1;
	patronList.at(id).SetBooksOut(newBooksOut);
}
// Fine balance after check out
void Patrons::EditPatron3(int id, int sec)
{
	double newFineBal = patronList.at(id).GetFineBal() + (sec / 86400) * (.25);
	patronList.at(id).SetFineBal(newFineBal);
}
// Setting new fine balance 
void Patrons::EditPatron4(int id, int bookID, LibraryItems& items)
{
	double bookCost = items.GetItemCost(bookID);
	double newBal = patronList.at(id).GetFineBal() + bookCost;
	patronList.at(id).SetFineBal(newBal);
}
// Remove Patron 
void Patrons::DeletePatron(int id)
{
	// Locate patron ID and match 
	int i = FindPatron2(id);
	
	if(patronList.at(i).GetBooksOut1() == 0 && patronList.at(i).GetFineBal() == 0.0 && PatronIDCheck(id) == true)
	{
		if(i == 0)
		{
			patronList.erase(patronList.begin());
		}
		else if(i != 0 && i != patronList.size())
		{
			patronList.erase(patronList.begin()+1);
		}
		else if(i == patronList.size())
		{
			patronList.pop_back();
		}
	}
	else
	{
		if(patronList.at(i).GetBooksOut1() != 0 && PatronIDCheck(id) == true)
		{
			cout << "Patron Has Exisiting Check Outs (Please Check In All Items Before Removing Patron)" << endl; 
		}
		else if(patronList.at(i).GetFineBal() != 0 && PatronIDCheck(id) == true)
		{
			cout << "Patron Has Exisiting Fine Balance (Please Pay All Fines Before Removing Patron)" << endl; 
		}
		else if(PatronIDCheck(id) != true)
		{
			cout << "Patron ID Not Found" << endl;
		}
	}
}
// Pay fine for overdue and lost 
void Patrons::PayFines(int id)
{
	if(PatronIDCheck(id) == true)
	{
		int i = FindPatron2(id);
		patronList.at(i).SetFineBal(0.0);
		PrintPatron(id);
	}
	else
	{
		if(PatronIDCheck(id) != true)
		{
			cout << "Patron ID Not Found" << endl;
		}
	}
}
// patron.dat
void Patrons::LoadPatrons()
{
	Patron patron;
	
	int id;
	string name;
	double balance;
	int books_out;
	
	int count = 0;
	
	ifstream fin("patron.dat");
	
	fin >> count;
	fin.ignore();
	int i;
	
	for(i = 0; i < count; i++)
	{
		getline(fin, name);
		fin >> id;
		fin.ignore();
		
		fin >> balance;
		fin.ignore();
		
		fin >> books_out;
		fin.ignore();
		
		patron.SetID(id);
		patron.SetName(name);
		patron.SetFineBal(balance);
		patron.SetBooksOut(books_out);
		
		patronList.push_back(patron);
	}
	fin.close();
}
// patrons.dat 
void Patrons::StorePatrons()
{
	ofstream fout("patrons.dat");
	
	fout << patronList.size() << endl; 
	
	unsigned int i;
	for(i = 0; i < patronList.size(); i++)
	{
		fout << patronList.at(i).GetName() << endl;
		fout << patronList.at(i).GetID() << endl;
		fout << patronList.at(i).GetFineBal() << endl;
		fout << patronList.at(i).GetBooksOut1() << endl;
	}
	fout.close();
}
// Accessors 
// Find using name 
int Patrons::FindPatron1(string name)
{	
	unsigned int i;
	for(i = 0; i < patronList.size(); i++)
	{
		if(patronList.at(i).GetName() == name)
		{
			return i;
		}
	}
	return 0;
}
// Find using ID 
int Patrons::FindPatron2(int id)
{
	unsigned int i; 
	for(i = 0; i < patronList.size(); i++)
	{
		if(patronList.at(i).GetID() == id)
		{
			return i;
		}
	}
	return 0;
}
// Patron ID Gets 
int Patrons::GetPatronID2(string name)
{
	return patronList.at(FindPatron1(name)).GetID();
}
int Patrons::GetPatronID3(int id)
{
	return patronList.at(FindPatron2(id)).GetID();
}
bool Patrons::PatronIDCheck(int id)
{
	if(patronList.at(FindPatron2(id)).GetID() == id)
	{
		return true;
	}
	return 0;
}
int Patrons::GetBooksOut2(int id)
{
	return patronList.at(FindPatron2(id)).GetBooksOut1();
}
// Output single patron 
void Patrons::PrintPatron(int id)
{
	if(PatronIDCheck(id) == true)
	{
		int i = FindPatron2(id);
		cout << "NAME: " << patronList.at(i).GetName() << " | ";
		cout << "PATRON ID: " << patronList.at(i).GetID() << " | ";
		cout << "FINE BALANCE: " << patronList.at(i).GetFineBal() << " | ";
		cout << "ITEMS OUT: " << patronList.at(i).GetBooksOut1() << endl << endl; 
	}
}
// Output all patrons 
void Patrons::PrintPatrons()
{
	cout << "ALL PATRONS:" << endl << endl;

	unsigned int i;
	for(i = 0; i < patronList.size(); i++)
	{
		cout << "NAME: " << patronList.at(i).GetName() << " | ";
		cout << "PATRON ID: " << patronList.at(i).GetID() << " | ";
		cout << "FINE BALANCE: " << patronList.at(i).GetFineBal() << " | ";
		cout << "ITEMS OUT: " << patronList.at(i).GetBooksOut1() << endl << endl; 
	}
	cout << endl; 
}